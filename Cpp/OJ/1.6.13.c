#include <stdio.h>
#include <stdbool.h>
int main(void) {
    char bignums[30], carry, i, *p;
    bool haveFactor=false;
    scanf("%s", bignums);
    for(i=2; i<=9; i++) {
        for(carry=0, p=bignums; *p; p++) carry=(carry*10+(*p-'0'))%i;
        if(carry==0) {
            printf("%d ",i);
            haveFactor=true;
        }
    }
    if(haveFactor!=true) printf("none");
    printf("\n");
    return 0;
}