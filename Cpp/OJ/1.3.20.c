#include <stdio.h>
int main(void) {
    unsigned in;
    scanf("%u", &in);
    if(in == 0) printf("%d\n", 1);
    else printf("%d\n", 2 << (in - 1));
    return 0;
}