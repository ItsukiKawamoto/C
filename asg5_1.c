#include <stdio.h>

int calcinpro(int *a, int *b);

int main() {
    int a[] = {3, 1, 2};
    int b[] = {-2, 5, 7};
    int c[] = {3, -4, 8};
    int d[] = {2, 1, 3};
    int e[] = {5, -2, 2};
    int f[] = {4, 2, -1};

    printf("%d\n", calcinpro(a, b)); // (3, 1, 2)と(-2, 5, 7)の内積を出力
    printf("%d\n", calcinpro(c, d)); // (3, -4, 8)と(2, 1, 3)の内積を出力
    printf("%d\n", calcinpro(e, f)); // (5, -2, 2)と(4, 2, -1)の内積を出力

    return 0;
}

int calcinpro(int *a, int *b) {
    return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}