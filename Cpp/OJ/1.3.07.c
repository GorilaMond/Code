#include<stdio.h>
main(){
double x,t,arr[4]; int i=3;
scanf("%lf",&x);
while(i>=0) scanf("%lf",arr+i--);
for(t=x,i=1;i<=3;i++){
arr[0]+=t*arr[i];
t*=x;
}
printf("%.7lf\n",arr[0]);
}