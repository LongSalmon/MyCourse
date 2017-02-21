#include <stdio.h>

int main()
{
    int i, j, k;
    for(i = 0; i < 11; i++) {
        k = 21 - (i * 2 + 1) / 2;
        for(j = 0; j < k; j++ ) {
            printf(" ");
        }
        for(j = 0; j < i * 2 + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
