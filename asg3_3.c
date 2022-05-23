#include <stdio.h>

int main() {
    int i, j, my_id;
    j = 1;
    my_id = 73;

    for (int n = 3; n <= my_id; n++) {
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
    }
    printf("\n");

    return 0;
}