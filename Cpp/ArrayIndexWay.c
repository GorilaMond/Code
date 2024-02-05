#include <stdio.h>

#include "MacroPlayground.h"

int main(void)
{
    SHOW_AND_PARSE(int a[3][2] = {3, 2, 1});
    for (int i = 0; i < 3; i++)
    {
        printf("a[0][%d] = %d\n", i, a[0][i]);
    }
    return 0;
}