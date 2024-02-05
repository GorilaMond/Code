#include<stdio.h>
main(){
float x1,y1,x2,y2,x3,y3,s;
scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
s=1./2*(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
s=s>0?s:-s;
printf("%.2f",s);
}