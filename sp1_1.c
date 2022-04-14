#include <stdio.h>

int main() {
    for (int i = 1; i < 11; i++) {
        int ans = 1;
        for (int j = 1; j < i + 1; j++) {
            ans *= j;
        }
        printf("%d\n", ans);
    }
}