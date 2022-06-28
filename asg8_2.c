#include <math.h>
#include <stdio.h>

int main() {
    char image[21][21];

    for (int j = 0; j < 21; j++) {
        float y = j - 10;
        for (int i = 0; i < 21; i++) {
            float x = i - 10;
            if (x * x + y * y < 90) {
                if (fabsf(x) < 5 && fabsf(y) < 5) { // 条件|x| < 5 ∧ |y| < 5
                    image[j][i] = 'x';
                } else {
                    image[j][i] = '#';
                }
            } else {
                image[j][i] = '.';
            }
        }
    }

    for (int j = 0; j < 21; j++) {
        for (int i = 0; i < 21; i++) {
            printf("%c ", image[j][i]);
        }
        printf("\n");
    }

    return 0;
}