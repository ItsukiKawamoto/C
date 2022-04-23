#include <math.h>
#include <stdio.h>

int main() {
    const double start = 0.0;
    const double end = 2.0;
    for (int bandNum = 1000; bandNum < 10000; bandNum += 100) {
        double dx = (end - start) / bandNum;
        double sum = 0.0;
        for (double i = start; i < end; i += dx) {
            sum += (pow(i, 3.0) + pow((i + dx), 3.0)) * dx / 2.0;
        }
        printf("%d : ", bandNum);
        printf("%lf\n", sum);
    }
}