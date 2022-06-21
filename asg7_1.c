#include <stdio.h>

float get_average(float kamoku[]);
float get_variance(float kamoku[]);

int main() {
    float kokugo[10], eigo[10];

    for (int i = 0; i < 10; i++) {
        scanf("%f%f", &kokugo[i], &eigo[i]);
    }
    printf("kokugo no bunsan = %5.1f\n", get_variance(kokugo));
    printf("eigo   no bunsan = %5.1f\n", get_variance(eigo));

    return 0;
}

float get_average(float kamoku[]) {
    float sum = 0;

    for (int i = 0; i < 10; i++) {
        sum += kamoku[i];
    }

    return sum / 10;
}

float get_variance(float kamoku[]) {
    float avg_kamoku = get_average(kamoku);
    float sq_deviation[10]; // 偏差の二乗を記録する配列

    for (int i = 0; i < 10; i++) {
        sq_deviation[i] = (kamoku[i] - avg_kamoku) * (kamoku[i] - avg_kamoku);
    }

    return get_average(sq_deviation); // 偏差の二乗の平均（分散）を返す
}