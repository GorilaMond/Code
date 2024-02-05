#include<stdio.h>
main(){
short n,a,b=0,l=1000;
scanf("%hd",&n);
while(n>0){
scanf("%hd",&a);
if(a>b)b=a;
if(a<l)l=a;
n--;
}
printf("%d",b-l);
}