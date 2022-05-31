#include <stdio.h>

int main() {
    char i;

    printf("Decimal  Octal  Hexadecimal  Charactor\n");
    for (i = 0; i < 0x7f; i = i + 1) {
        if (i >= 0x20) {
            printf("    %3d%#7o     %#8x         %c\n", i, i, i, i);
        } else {
            printf("    %3d%#7o     %#8x         ^%c\n", i, i, i, i + 0x40);
        }
    }
}