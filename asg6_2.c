#include <stdio.h>

// 行列の積を計算する関数
void calcMatrixProduct(int a[2][2], int b[2][2]);

int ans[2][2] = {}; // 計算結果を保存する二次元配列

int main() {
    int A[2][2] = {}; // 行列Aを保存する二次元配列
    int B[2][2] = {}; // 行列Bを保存する二次元配列

    printf("Input matrix A: ");
    fflush(stdout);
    // 入力された行列Aの読み取り
    scanf("%d %d; %d %d", &A[0][0], &A[0][1], &A[1][0], &A[1][1]);
    // 行列Aの値を表示
    printf("Matrix A is…\n%4d%4d\n%4d%4d\n\n", A[0][0], A[0][1], A[1][0],
           A[1][1]);

    printf("Input matrix B: ");
    fflush(stdout);
    // 入力された行列Bの読み取り
    scanf("%d %d; %d %d", &B[0][0], &B[0][1], &B[1][0], &B[1][1]);
    // 行列Bの値を表示
    printf("Matrix B is…\n%4d%4d\n%4d%4d\n\n", B[0][0], B[0][1], B[1][0],
           B[1][1]);

    // 行列AとBの積を計算
    calcMatrixProduct(A, B);
    // 結果を表示
    printf("The product of A and B is…\n%4d%4d\n%4d%4d\n", ans[0][0], ans[0][1],
           ans[1][0], ans[1][1]);

    return 0;
}

void calcMatrixProduct(int a[2][2], int b[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            // 行列の積を成分ごとに計算し結果を代入
            ans[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }
}