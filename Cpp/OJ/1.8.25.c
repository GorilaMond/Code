/*
# 25:螺旋加密

## 描述

Chip和Dale发明了一种文本信息加密技术。他们事先秘密约定好矩阵的行数和列数。接着，将字符按如下方式编码：

1. 所有文本只包含大写字母和空格。
2. 每个字符均赋予一个数值：空格=0，A=1，B=2，……，Y=25，Z=26。

按照下图所示的方式，将每个字符对应数值的5位二进制数依次填入矩阵。最后用0将矩阵补充完整。例如，对于信息“ACM”，行列数均为4时，矩阵将被填充为：

()[http://media.openjudge.cn/images/3421.jpg]

将矩阵中的数字按行连起来形成数字串，完成加密。例子中的信息最终会被加密为：0000110100101100。

## 输入

一行。首先是两个整数R(1≤R≤20)和C(1≤C≤20)，表示行数和列数。之后是一个只包含大写字母和空格的字符串。字符串的长度≤(R*C)/5。R和C之间以及C和字符串之间均用单个空格隔开。

## 输出

一行，为加密后的二进制串。注意你可能需要用0将矩阵补充完整。

## 样例输入
```c
4 4 ACM
```

## 样例输出
```
0000110100101100
```

## 来源

Greater NY 2007
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
bool codelist[27][5];
void initcodelist(void) {
    int i, j, c;
    for(c=i=0;i<27;c=++i)
        for(j=4;j>=0;j--) {
            codelist[i][j]=c%2;
            c/=2;
        }
    return;
}
bool* encode(char *str, int len) {
    int i, j=0, k;
    bool *bi=(bool*)malloc(sizeof(bool)*len);
    for(; *str; str++) {
        i=(*str==' '?0:(*str-'A'+1));
        for(k=0;k<5;k++,j++) bi[j]=codelist[i][k];
    }
    while(j<len) bi[j++]=0;
    return bi;
}
int main(void) {
    int r, c, bi, blen, rp;
    int limit[4][2]={{0,0},{1,0},{0,0},{1,0}}; 
    // 0坐标（x）的下限为0，1坐标（y）的上限初始化为0，0坐标的上限初始化为0，1坐标的下限为0
    // 顺序为从外到内螺旋遇到的边界的顺序
    int pos[2]={0,0};
    int step[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    char *str;
    bool **mtx, *bistr;
    scanf("%d %d ", &r, &c);
    blen=r*c; limit[1][1]=c-1; limit[2][1]=r-1;
    str=(char*)malloc(sizeof(char)*blen/5);
    gets(str);
    initcodelist(); bistr=encode(str, blen);
    mtx=(bool**)malloc(sizeof(bool*)*r);
    for(*pos=0;*pos<r;(*pos)++) mtx[*pos]=(bool*)malloc(sizeof(bool)*c);
    for(pos[0]=pos[1]=bi=rp=0; bi<blen; bi++) {
        mtx[pos[0]][pos[1]]=bistr[bi];
        pos[0]+=step[rp][0];
        pos[1]+=step[rp][1];
        if(pos[limit[(rp+1)%4][0]]==limit[(rp+1)%4][1]) {
            limit[rp][1]+=step[(rp+1)%4][limit[rp][0]];
            rp=(rp+1)%4;
        }
    }
    for(pos[0]=0;pos[0]<r;pos[0]++)
        for(pos[1]=0;pos[1]<c;pos[1]++)
            putchar(mtx[pos[0]][pos[1]]+'0');
    putchar('\n');
    for(*pos=0;*pos<r;(*pos)++) free(mtx[*pos]); 
    free(mtx); free(bistr); free(str);
    return 0;
}