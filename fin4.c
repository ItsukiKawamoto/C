#include <stdio.h>

void get_max_student(int num, int score[]);

int score[] = {98, 50, 47, 68, 77, 90, 92, 98, 69, 83, 64, 98};

int main() {
    int N = sizeof(score) / sizeof(int);
    get_max_student(N, score);

    return 0;
}

void get_max_student(int num, int score[]) {
    int max = score[0];

    for (int i = 1; i < num; i++) {
        if (score[i] > max) {
            max = score[i];
        }
    }
    printf("max_student: ");
    for (int i = 0; i < num; i++) {
        if (score[i] == max) {
            printf("%d ", i);
        }
    }
    printf("\n");
}