#include <stdio.h>

int main(void) {
    int warareru;
    unsigned short waru;

    printf("割られる数（dividend）>> ");
    scanf("%d", &warareru);

    printf("割る数（divisor）>> ");
    scanf("%hd", &waru);

    printf("%hu\n", waru);
    printf("余り（remainder）= %d\n", warareru - (warareru / waru) * waru);

    return 0;
}