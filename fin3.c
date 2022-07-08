#include <stdio.h>

char utol(char letter) { return (letter + 0x20); }

int main() {
    char buf;

    printf("Input a letter: ");
    scanf("%c", &buf);
    if (buf < 0x41 || buf > 0x5A) {
        return 1;
    }
    printf("The lower case is %c\n", utol(buf));

    return 0;
}