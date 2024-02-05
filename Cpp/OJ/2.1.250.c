#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ccomp(const void*a, const void*b) {return *(char*)b-*(char*)a;}
int main(void) {
	int t; char s[13], l, *v,*w,*x,*y,*z;
	while(1){
next:   
		scanf("%u %s", &t, s);
		if(!t && !strcmp(s, "END")) break;
		l=strlen(s);
#define L(x) for(x=s;*x;x++){
		L(x)*x-=64;}
		qsort(s, l, 1, ccomp);
		L(v)
		L(w)if(w==v)continue;
		L(x)if(x==w||x==v)continue;
		L(y)if(y==x||y==w||y==v)continue;
		L(z)if(z==y||z==x||z==w||z==v)continue;
			if(*v-*w**w+*x**x**x-*y**y**y**y+*z**z**z**z**z==t) {
				printf("%c%c%c%c%c\n",*v+64,*w+64,*x+64,*y+64,*z+64);
				goto next;
			}
		}}}}}
		printf("no solution\n");
	}
}