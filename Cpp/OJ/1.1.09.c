#include <stdio.h>
int main(void) {
#define SIZE 4
    char c, i, j;
    scanf("%c",&c);
    for(i = SIZE / 2; i > 0; i--) {
        for(j = 0; j < i; j++) printf(" ", c);
        for(j = SIZE - 2*i; j > 0; j--) printf("%c", c);
        for(j = 0; j < i; j++) printf(" ", c);
        printf("\n");
    }
    for(i = 0; i <= SIZE / 2; i++) {
        for(j = 0; j < i; j++) printf(" ", c);
        for(j = SIZE - 2*i; j > 0; j--) printf("%c", c);
        for(j = 0; j < i; j++) printf(" ", c);
        printf("\n");
    }
    return 0;
}