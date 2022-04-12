#include <stdio.h>

int addup(int i); // 関数のプロトタイプ宣言

int main() {
    int i;
    int sum;
    i = 0;
    sum = 0;
    sum = addup(i);
    printf("i was squared - it now equals %d\n", sum);
}

int addup(int i) {
    while (i <= 5) {
        i = i + 1;
        printf("i is %d\n", i); // 上の計算結果を出力
    }
    i = i * i;
    return (i);
}
