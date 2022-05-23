#include <stdio.h>

int main() {
    int i, j, n, my_id;
    j = 1;
    n = 3;
    my_id = 73;

    while (n <= my_id) {
        i = 2;
        while (i < n) {
            if (n % i == 0)
                break;
            i++;
        }
        if (i == n) {
            printf("%5d", n);
            if (j % 10 == 0) {
                printf("\n");
            }
            j++;
        }
        n++;
    }
    printf("\n");

    return 0;
}