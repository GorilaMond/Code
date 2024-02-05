#include<stdio.h>
main(){
long a,b;char c;
scanf("%ld%ld",&a,&b);
if(a>b)c='>';
else if(a==b)c='=';
else c='<';
putchar(c);
}