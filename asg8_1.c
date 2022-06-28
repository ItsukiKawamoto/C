#include <stdio.h>

int main() {
    char input[80];

    printf("Enter a string: ");
    scanf("%s", input);

    char memory = input[0]; // 1つ前の文字を記憶する変数
    for (int i = 1; input[i] != '\0'; i++) {
        if (input[i] == memory) { // 一致したら置換
            input[i - 1] = '*';
            input[i] = '*';
        }
        memory = input[i]; // 記憶する文字を更新
    }

    printf("%s\n", input);

    return 0;
}