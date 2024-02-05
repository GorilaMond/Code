#include<stdio.h>
main(){
int m,n;
scanf("%d%d",&m,&n);
if(m%2==0)m++;
if(n%2==0)n--;
printf("%d",m>n?0:m==n?m:(m+n)*((n-m)/2+1)/2);
}