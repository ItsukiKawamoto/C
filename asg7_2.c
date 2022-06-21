#include <stdio.h>

float get_min(float kamoku[]);

int main() {
    float kokugo[10], eigo[10];

    for (int i = 0; i < 10; i++) {
        scanf("%f%f", &kokugo[i], &eigo[i]);
    }
    printf("min_kokugo = %5.1f\n", get_min(kokugo));
    printf("min_eigo   = %5.1f\n", get_min(eigo));

    return 0;
}

float get_min(float kamoku[]) {
    float min = kamoku[0];

    for (int i = 1; i < 10; i++) {
        if (min > kamoku[i]) {
            min = kamoku[i];
        }
    }

    return min;
}