#include <stdio.h>

int calcinpro(int *a, int *b);

int main() {
    int a[] = {3, 1, 2};
    int b[] = {-2, 5, 7};
    int c[] = {3, -4, 8};
    int d[] = {2, 1, 3};
    int e[] = {5, -2, 2};
    int f[] = {4, 2, -1};

    printf("%d\n", calcinpro(a, b));
    printf("%d\n", calcinpro(c, d));
    printf("%d\n", calcinpro(e, f));

    return 0;
}

int calcinpro(int *a, int *b) {
    return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}