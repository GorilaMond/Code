#include <stdio.h>
main(){
	char c=getchar(); int i,j;
	for(i=1;i<=3;i++){
		for(j=3;j>i;j--)putchar(' ');
		for(j=2*i;j>1;j--)putchar(c);
		putchar('\n');
	}
}