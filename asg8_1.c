#include <stdio.h>

int main() {
    char input[80];

    printf("Enter a string: ");
    scanf("%s", input);

    char memory = input[0];
    for (int i = 1; input[i] != '\0'; i++) {
        if (input[i] == memory) {
            input[i - 1] = '*';
            input[i] = '*';
        }
        memory = input[i];
    }

    printf("%s\n", input);

    return 0;
}