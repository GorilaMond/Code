#include<stdio.h>
main(){
int a,b;
scanf("%d%d",&a,&b);
printf("%d",(a<60)+(b<60)-1?0:1);
}