/* 
# 08:病人排队

总时间限制: 1000ms 内存限制: 65536kB

## 描述

病人登记看病，编写一个程序，将登记的病人按照以下原则排出看病的先后顺序：

1. 老年人（年龄 >= 60岁）比非老年人优先看病。
2. 老年人按年龄从大到小的顺序看病，年龄相同的按登记的先后顺序排序。
3. 非老年人按登记的先后顺序看病。

## 输入

第1行，输入一个小于100的正整数，表示病人的个数；
后面按照病人登记的先后顺序，每行输入一个病人的信息，包括：
一个长度小于10的字符串表示病人的ID（每个病人的ID各不相同且只含数字和字母），
一个整数表示病人的年龄，中间用单个空格隔开。

## 输出

按排好的看病顺序输出病人的ID，每行一个。

## 样例输入
```
5
021075 40
004003 15
010158 67
021033 75
102012 30
```

## 样例输出
```
021033
010158
021075
004003
102012
```

## 来源
习题(14-6) 
*/

#include <stdio.h>
#include <malloc.h>
int main(void) {
    unsigned n, i, j;
    struct info {char id[10]; unsigned age; struct info* next;} *pool, young, old, *yp=&young, *op;
    scanf("%u", &n);
    pool=(struct info*)malloc(sizeof(struct info)*n);
    for(i=young.next=old.next=0; i<n; i++,pool++) {
        scanf("%s %u", pool[0].id, &pool[0].age);
        if(pool[0].age>=60) {
            for(op=&old; op->next && op->next->age>=pool[0].age; op=op->next);
            pool[0].next=op->next;
            op->next=pool;
        } else {
            yp->next=pool;
            pool->next=0;
            yp=pool;
        }
    }
    for(op=old.next; op; op=op->next) printf("%s\n", op->id);
    for(yp=young.next; yp; yp=yp->next) printf("%s\n", yp->id);
}