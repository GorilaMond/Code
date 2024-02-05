#include<stdio.h>
main(){
int a,b,r;char c, *s=0;
scanf("%d%d %c",&a,&b,&c);
if(c=='+')r=a+b;
else if(c=='-')r=a-b;
else if(c=='*')r=a*b;
else if(c=='/')
if(b)r=a/b;else s="Divided by zero!";
else s="Invaild operator!";
if(s)printf("%s",s);
else printf("%d",r);
}