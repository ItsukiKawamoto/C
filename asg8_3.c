#include <stdio.h>

int main() {
    double m[2][2], u[2][2], v[2][2] = {};

    m[0][0] = 6;
    m[0][1] = 1;
    m[1][0] = 5;
    m[1][1] = 1;

    u[0][0] = 1;
    u[0][1] = -1;
    u[1][0] = 2;
    u[1][1] = -2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                v[i][j] += m[i][k] * u[k][j];
            }
        }
    }

    printf("v =\n%5.1lf%5.1lf\n%5.1lf%5.1lf\n", v[0][0], v[0][1], v[1][0],
           v[1][1]);

    return 0;
}