#include <stdio.h>
#include <math.h>

int main() {
    int bandNum = 1000;
    double dx = 2.0 / bandNum;
    double sum = 0.0;
    for (double i = 0.0; i < 2.0; i += dx) {
        sum += (pow(i, 3.0) + pow((i + dx), 3.0)) * dx / 2.0;
    }
    printf("%lf", sum);
}