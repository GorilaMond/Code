#include<stdio.h>
main(){
int a,f=0;
#define _(n) if(a%n==0)putchar(n+48)&&(f=1)
#define B if(f)putchar(' ')
scanf("%d",&a);
_(3);B;_(5);B;_(7);
if(!f)putchar('n');
}