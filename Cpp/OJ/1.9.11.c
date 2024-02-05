#include <stdio.h>
int main(void) {
    char str[1001];
    int i,j,k;
    scanf("%d", &k);
    scanf("%s", str);
    for(i=0;str[i];i=j) {
        for(j=i+1; str[j]==str[i]; j++);
        if((j-i)>=k) {
            printf("%c\n", str[i]);
            return 0;
        }
    }
    printf("No\n");
}