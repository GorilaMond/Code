#include <stdio.h>
int main(void) {
    int n, c, i;
    scanf("%d", &n);
    if (n == 0) printf("0\n");
    else {
        for(i=n; i>1; i--) {
            scanf("%d", &c);
            printf("%d ", c*i);
        }
        scanf("%d", &c);
        printf("%d\n", c);
    }
    return 0;
}