/*
# 03:矩形分割

总时间限制: 1000ms 内存限制: 65536kB

## 描述

平面上有一个大矩形，其左下角坐标（0，0），右上角坐标（R,R)。
大矩形内部包含一些小矩形，小矩形都平行于坐标轴且互不重叠。
所有矩形的顶点都是整点。要求画一根平行于y轴的直线x=k（k是整数) ，
使得这些小矩形落在直线左边的面积必须大于等于落在右边的面积，且两边面积之差最小。
并且，要使得大矩形在直线左边的的面积尽可能大。
注意：若直线穿过一个小矩形，将会把它切成两个部分，分属左右两侧。

## 输入

第一行是整数R，表示大矩形的右上角坐标是(R,R) (1 <= R <= 1,000,000)。
接下来的一行是整数N,表示一共有N个小矩形(0 < N <= 10000)。
再接下来有N 行。每行有4个整数，L,T, W 和 H, 表示有一个小矩形的左上角坐标是(L,T),宽度是W，高度是H (0<=L,T <= R, 0 < W,H <= R). 小矩形不会有位于大矩形之外的部分。

## 输出

输出整数n，表示答案应该是直线 x=n。 如果必要的话，x=R也可以是答案。

## 样例输入
```
1000
2
1 1 2 1
5 1 2 1
```

## 样例输出
```
5
```
*/


// #include <stdio.h>
// #include <malloc.h>
// int main(void) {
//     unsigned i, j, k, R, N, **rect;
//     unsigned long ls, ss;
//     scanf("%d\n%d", &R, &N);
//     rect=(unsigned**)malloc(sizeof(unsigned*)*N);
//     for(ss=ls=i=0; i<N; i++) {
//         rect[i]=(unsigned*)malloc(sizeof(unsigned)*4);
//         for(j=0; j<4; j++) scanf("%u", rect[i]+j);
//         ss+=rect[i][2]*rect[i][3];
//     }
//     for(k=1; k<=R; k++) {
//         for(i=0; i<N; i++) {
//             if(rect[i][0]<k && rect[i][0]+rect[i][2]>=k)
//                 ls+=rect[i][3];
//         }
//         if(ls>=ss-ls) {
//             for(j=R,i=0; i<N; i++)
//                 if (rect[i][0]>=k) {
//                     if(rect[i][0]<j)
//                         j=rect[i][0];
//                 } else if(k-rect[i][0]<rect[i][2]) {
//                     printf("%u\n", k);
//                     goto done;
//                 }
//             printf("%u\n", j);
//             goto done;
//         }
//     }
// done:
//     for(i=0; i<N; i++) free(rect[i]);
//     free(rect);
// }

#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(void) {
    unsigned i, j, R, N, t, L, T, W, H, *a;
    unsigned long *sa;
	scanf("%u\n%u", &R, &N);
    a=malloc(sizeof(unsigned)*R); memset(a, 0, R);
    sa=malloc(sizeof(unsigned long)*R); memset(sa, 0, R);
	for(i=0; i<N; i++){
		scanf("%u %u %u %u", &L, &T, &W, &H);
		for(int j=0;j<W;j++) a[L+j]+=H;
	}
	for(sa[0]=a[0],i=1; i<R; i++) sa[i]=sa[i-1]+a[i];

    for(i=0,j=R-1; i<j;){
		t=i+(j-i)/2;
		if(2*sa[t]>=sa[R-1]) j=t;
		else i=t+1;
	}

	for(; i<R && sa[i+1]==sa[i]; i++);
	printf("%u\n", i+1);
}