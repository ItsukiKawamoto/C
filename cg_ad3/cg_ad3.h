static int STEP = 0;

void collision_walls();

void coloring(double *r, double *g, double *b, double min, double max,
              double val);

struct Node {
  int data;
  struct Node *next;
};

int hash(double x, double y);

int add(int hash, int num);

void clear();

typedef struct {
  double x;
  double y;
} Vector;

Vector vSet(double x, double y);

Vector vAdd(Vector a, Vector b);

Vector vSub(Vector a, Vector b);

Vector vMult(Vector a, double n);

Vector vDiv(Vector a, double n);

double vDot(Vector a, Vector b);

double vAbs(Vector a);

Vector vNorm(Vector a);

Vector vRand();
