#include <stdio.h>
int main(void) {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    n -= y % x ? y / x + 1 : y / x;
    printf("%d\n", n > 0 ? n : 0);
    return 0;
}