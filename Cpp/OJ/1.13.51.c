#include <stdio.h>
#include <string.h>
char scb[26], dcb[26], stb[100], dtb[100];
int main(void) {
    char src[101], des[101], len, i;
    scanf("%s\n%s", src, des);
    if((len=strlen(src))!=strlen(des)) goto false;
    i=0; while(i<len) {
        scb[src[i]-'A']++;
        dcb[des[i]-'A']++;
        i++;
    }
    i=0; while(i<26) {
        stb[scb[i]]++;
        dtb[dcb[i]]++;
        i++;
    }
    i=0; while(i<len) if(stb[i]!=dtb[i++]) goto false;
    printf("YES\n");
    return 0;
false:
    printf("NO\n");
}