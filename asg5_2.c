#include <math.h>
#include <stdio.h>

double calcdist(double *a, double *b);

int main() {
    double a[] = {(double)1, (double)1, (double)1};
    double b[] = {(double)0, (double)1, (double)1};
    double c[] = {(double)10, (double)-3, (double)-1};
    double d[] = {(double)6, (double)3, (double)-5};
    double e[] = {10.0, 3.1, 5.3};
    double f[] = {-2.0, -3.0, 5.2};

    printf("%f\n", calcdist(a, b)); // (1, 1, 1)と(0, 1, 1)の距離を出力
    printf("%f\n", calcdist(c, d)); // (10, -3, -1)と(6, 3, -5)の距離を出力
    printf("%f\n", calcdist(e, f)); // (10.0, 3.1, 5.3)と(-2.0, -3.0, 5.2)の距離を出力

    return 0;
}

double calcdist(double *a, double *b) {
    return (sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]) +
                 (a[2] - b[2]) * (a[2] - b[2])));
}