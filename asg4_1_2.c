#include <stdio.h>

int main() {
    unsigned char i = 1, j;
    
    while (i > 0) {
        j = i;
        i = i + 1;
    }
    printf(" i = %hhd(%hhu, %#hhx), j = %hhd(%hhu, %#hhx)\n", i, i, i, j, j, j);

    return 0;
}