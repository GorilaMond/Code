/* 
# 05:统计单词数

总时间限制: 1000ms 内存限制: 65536kB

## 描述

一般的文本编辑器都有查找单词的功能，该功能可以快速定位特定单词在文章中的位置，有的还能统计出特定单词在文章中出现的次数。

现在，请你编程实现这一功能，具体要求是：给定一个单词，请你输出它在给定的文章中出现的次数和第一次出现的位置。
*注意：匹配单词时，不区分大小写，但要求完全匹配，即给定单词必须与文章中的某一独立单词在不区分大小写的情况下完全相同（参见样例1），如果给定单词仅是文章中某一单词的一部分则不算匹配（参见样例2）。*

## 输入

2 行。
第 1 行为一个字符串，其中只含字母，表示给定单词；
第 2 行为一个字符串，其中只可能包含字母和空格，表示给定的文章。

## 输出

只有一行，如果在文章中找到给定单词则输出两个整数，两个整数之间用一个空格隔开，分别是单词在文章中出现的次数和第一次出现的位置（即在文章中第一次出现时，单词首字母在文章中的位置，位置从0开始）；如果单词在文章中没有出现，则直接输出一个整数-1。

## 样例输入
```
样例 #1：
To
to be or not to be is a question

样例 #2：
to
Did the Ottoman Empire lose its power at that time
```

## 样例输出
```
样例 #1：
2 0

样例 #2：
-1
```

## 来源

NOIP2011复赛 普及组 第二题 
*/

#include <stdio.h>
int main(void) {
    char word[46], text[1000000], *wp=word, *tp=text;
    int count=0, orig=-1;
    gets(word); gets(text);
    while(*wp) {
        if(*wp>='A'&&*wp<='Z') *wp+=32;
        wp++;
    }
    while(*tp) {
        wp=word;
        while(*wp&&*wp==*tp||*wp-32==*tp) {
            wp++;
            tp++;
        }
        if(!*wp&&*tp==' '||!*tp) {
            count++;
            if(orig<0) orig=tp-text-(wp-word);
        } else while(*tp&&*tp!=' ') tp++;
        while(*tp&&*tp==' ') tp++;
    }
    if(orig>=0) printf("%d %d\n", count, orig);
    else printf("%d\n", orig);
}