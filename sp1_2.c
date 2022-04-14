#include <math.h>
#include <stdio.h>

int main() {
    int bandNum = 1000;
    double start = 0.0;
    double end = 2.0;
    double dx = (end - start) / bandNum;
    double sum = 0.0;
    for (double i = start; i < end; i += dx) {
        sum += (pow(i, 3.0) + pow((i + dx), 3.0)) * dx / 2.0;
    }
    printf("%lf", sum);
}