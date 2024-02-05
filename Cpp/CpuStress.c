//gcc cpu.c -lm -g --no-omit-frame-pointer

#include <stdio.h>
#include <math.h>
#include <time.h>

#define N __INT_MAX__
#define RAND_MAX 100

#define noinline __attribute__((noinline))

noinline double func3(double x)
{
    return sqrt(x);
}
noinline double func2(double x)
{
    return sqrt(func3(x));
}
noinline double func1(double x)
{
    return sqrt(func2(x));
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for (int i = 0; i < N; i++)
    {
        double x = rand() / (double)RAND_MAX;
        func1(x);
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}
