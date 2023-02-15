#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

// #define DEBUG

#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cg_ad3.h"

/*************** parameters ****************/
#define GRID_LENGTH 5.0  // バケット長
static const int GRID_ROOT =
    (200.0 + GRID_LENGTH - 1.0) / GRID_LENGTH;  // バケット数の平方根
struct Node array[GRID_ROOT * GRID_ROOT];       // ハッシュテーブル

#define N 6                      // 弾性体の行数
#define M 3                      // 弾性体の列数
#define S_N 60                   // 小球の行数
#define S_M 20                   // 小球の列数
#define NUM (N * M + S_N * S_M)  // 球の総数

Vector p[NUM];  // 球の位置
Vector v[NUM];  // 球の速度
Vector f[NUM];  // 球に働く力
double r[NUM];  // 球の半径
double m[NUM];  // 球の質量

static const double DT = 0.002;    // 時間刻み幅
static const double THETA = 30.0;  // 初期回転角
static const double E = 0.95;      // 反発係数
static const double L = 6.5;       // 自然長
static const double K = 200.0;     // バネ定数
static const double C = 80.0;      // ダッシュポット定数
static const double G = 9.8;       // 重力加速度
static int REFLESH_RATE = 100;     // 画面の更新頻度
/*******************************************/

void calc_init() {
  /*************** initialize *****************/
  for (int i = 0; i < GRID_ROOT * GRID_ROOT; i++) {
    array[i].data = -1;
    array[i].next = NULL;
  }
  for (int i = 0; i < S_N; i++) {
    for (int j = 0; j < S_M; j++) {
      p[S_M * i + j] = vAdd(
          vAdd(vSet(-98.5 + i * 1.0E-5, -98.5), vMult(vSet(1.0, 0.0), j * 3.0)),
          vMult(vSet(0.0, 1.0), i * 3.0));
      v[S_M * i + j] = vSet(0.0, 0.0);
      f[S_M * i + j] = vSet(0.0, 0.0);
      r[S_M * i + j] = 1.5;
      m[S_M * i + j] = 1.0;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      p[S_N * S_M + M * i + j] =
          vAdd(vAdd(vSet(0.0, -97.0), vMult(vSet(1.0, 0.0), j * L)),
               vMult(vSet(0.0, 1.0), i * L));
      v[S_N * S_M + M * i + j] = vSet(0.0, 0.0);
      f[S_N * S_M + M * i + j] = vSet(0.0, 0.0);
      r[S_N * S_M + M * i + j] = 3.0;
      m[S_N * S_M + M * i + j] = 4.0;
    }
  }
  /********************************************/
}

void calc_spring_damper(int i, int j, double k, double l, double c) {
  Vector d = vSub(p[j], p[i]);
  Vector n = vDiv(d, vAbs(d));
  double v_rel = vDot(vSub(v[j], v[i]), n);
  f[i] = vAdd(f[i], vMult(n, -k * (l - vAbs(d)) + c * v_rel));
  f[j] = vAdd(f[j], vMult(n, k * (l - vAbs(d)) - c * v_rel));
}

void calc_motion() {
  /*************** simulation *****************/
  clear();
  for (int i = 0; i < NUM; i++) {
    add(hash(p[i].x, p[i].y), i);
    f[i] = vSet(0.0, -m[i] * G);
  }
  for (int i = 0; i < NUM - 1; i++) {
    int bucket = hash(p[i].x, p[i].y);
    for (int s = bucket - GRID_ROOT; s <= bucket + GRID_ROOT; s += GRID_ROOT) {
      for (int t = s - 1; t <= s + 1; t++) {
        if (t >= 0 && t < GRID_ROOT * GRID_ROOT) {
          for (struct Node *ptr = &array[t]; ptr != NULL; ptr = ptr->next) {
            int j = ptr->data;
            if (i < j) {
              Vector d = vSub(p[j], p[i]);
              if (vAbs(d) <= r[i] + r[j]) {
                calc_spring_damper(i, j, K, r[i] + r[j], C);
              }
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      double k = 40000.0;
      double c = 300.0;

      if (j != M - 1)
        calc_spring_damper(S_N * S_M + M * i + j, S_N * S_M + M * i + j + 1, k,
                           L, c);
      if (i != N - 1)
        calc_spring_damper(S_N * S_M + M * i + j, S_N * S_M + M * (i + 1) + j,
                           k, L, c);
      if (j != M - 1 && i != N - 1)
        calc_spring_damper(S_N * S_M + M * i + j,
                           S_N * S_M + M * (i + 1) + j + 1, k, sqrt(2.0) * L,
                           c);
    }
  }
#ifndef DEBUG
  for (int i = 0; i < NUM; i++) {
    v[i] = vAdd(v[i], vMult(f[i], DT / m[i]));
    p[i] = vAdd(p[i], vMult(v[i], DT));
  }
#endif
  /********************************************/

  collision_walls();

  // 画面の再描画命令
  if (STEP % REFLESH_RATE == 0) {
    glutPostRedisplay();
  }
  STEP++;
}

// 壁の衝突処理
void collision_walls() {
  for (int i = 0; i < NUM; i++) {
    if (p[i].x - r[i] < -100) {
      p[i].x = -100.0 + r[i];
      v[i].x = -E * v[i].x;
    }
    if (100 < p[i].x + r[i]) {
      p[i].x = 100.0 - r[i];
      v[i].x = -E * v[i].x;
    }
    if (p[i].y - r[i] < -100) {
      p[i].y = -100.0 + r[i];
      v[i].y = -E * v[i].y;
    }
    if (100 < p[i].y + r[i]) {
      p[i].y = 100.0 - r[i];
      v[i].y = -E * v[i].y;
    }
  }
}

// カラーコンター
void coloring(double *r, double *g, double *b, double min, double max,
              double val) {
  double ratio = (val - min) / (max - min);
  if (ratio >= 0) {
    if (4 * ratio < 1) {
      *r = 0.0;
      *g = (4.0 * ratio);
      *b = 1.0;
    } else if (4 * ratio < 2) {
      *r = 0.0;
      *g = 1.0;
      *b = 1.0 - (4.0 * ratio - 1.0);
    } else if (4 * ratio < 3) {
      *r = (4.0 * ratio - 2.0);
      *g = 1.0;
      *b = 0.0;
    } else {
      *r = 1.0;
      *g = 1.0 - (4.0 * ratio - 3.0);
      *b = 0.0;
    }
  } else {
    *r = 0.0;
    *g = 0.0;
    *b = 1.0;
  }
}

// 球の描画
void draw_particles() {
  glClear(GL_COLOR_BUFFER_BIT);

  for (int i = 0; i < NUM; i++) {
    double red, green, blue;
    coloring(&red, &green, &blue, 0, 1, (double)(i) / (double)(NUM - 1.0));
    glColor3d(red, green, blue);
    glPointSize(2.0 * r[i] * 500.0 / 200.0);
    glEnable(GL_POINT_SMOOTH);

    glBegin(GL_POINTS);
    glVertex2d(p[i].x, p[i].y);
    glEnd();
  }
  glFlush();
}

int hash(double x, double y) {
  return floor((x + 100.0) / GRID_LENGTH) +
         floor((y + 100.0) / GRID_LENGTH) * GRID_ROOT;
}

int add(int hash, int num) {
  if (array[hash].data == -1) {
    array[hash].data = num;
  } else {
    struct Node *new;
    struct Node *ptr = &array[hash];

    new = (struct Node *)malloc(sizeof(struct Node));
    if (new == NULL) {
      return -1;
    }

    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = new;
    new->data = num;
    new->next = NULL;
  }
  return 0;
}

void clear() {
  for (int i = 0; i < GRID_ROOT * GRID_ROOT; i++) {
    array[i].data = -1;
    if (array[i].next != NULL) {
      struct Node *ptr = array[i].next;
      array[i].next = NULL;
      while (ptr != NULL) {
        struct Node *prev = ptr;
        ptr = ptr->next;
        free(prev);
      }
    }
  }
}

Vector vSet(double x, double y) {
  Vector a = {x, y};
  return a;
}

Vector vAdd(Vector a, Vector b) { return vSet(a.x + b.x, a.y + b.y); }

Vector vSub(Vector a, Vector b) { return vSet(a.x - b.x, a.y - b.y); }

Vector vMult(Vector a, double n) { return vSet(a.x * n, a.y * n); }

Vector vDiv(Vector a, double n) { return vSet(a.x / n, a.y / n); }

double vDot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }

double vAbs(Vector a) { return sqrt(vDot(a, a)); }

Vector vNorm(Vector a) { return vDiv(a, vAbs(a)); }

Vector vRand() {
  Vector a = {(double)rand() / RAND_MAX - 0.5, (double)rand() / RAND_MAX - 0.5};
  return vDiv(a, vAbs(a));
}

int main(int argc, char *argv[]) {
  srand((unsigned int)time(NULL));
  calc_init();

  glutInitWindowPosition(100, 100);
  glutInitWindowSize(500, 500);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutCreateWindow(argv[0]);
  glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glutDisplayFunc(draw_particles);
  glutIdleFunc(calc_motion);
  glutMainLoop();

  return 0;
}
