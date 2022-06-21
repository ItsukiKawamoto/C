#include <stdio.h>

int get_min_num(float kamoku[]);

int main() {
    float kokugo[10], eigo[10];

    for (int i = 0; i < 10; i++) {
        scanf("%f%f", &kokugo[i], &eigo[i]);
    }
    printf("min_num_kokugo = %d\n", get_min_num(kokugo));
    printf("min_num_eigo   = %d\n", get_min_num(eigo));

    return 0;
}

int get_min_num(float kamoku[]) {
    float min = kamoku[0];
    int min_num = 0;

    for (int i = 1; i < 10; i++) {
        if (min > kamoku[i]) {
            min = kamoku[i];
            min_num = i;
        }
    }

    return min_num;
}