#include<stdio.h>
main(){
int l;float a,b;char *s;
scanf("%d",&l);
a=l/1.2;
b=l/3.0+50;
if(a>b)s="Bike";
else if(a==b)s="All";
else s="Walk";
printf("%s",s);
}