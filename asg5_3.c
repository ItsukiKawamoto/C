#include <stdio.h>

char ltou(char letter) { return (letter - 0x20); }

int main() {
    printf("I am %c.%c\n", ltou('i'), ltou('k'));

    return 0;
}