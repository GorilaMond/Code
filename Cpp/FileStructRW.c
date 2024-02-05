#include <stdio.h>
#include <unistd.h>

void r() {
    int val;
    FILE *f = fopen("tmp", "r");
    fscanf(f, "%d", &val);
    printf("%d\n", val);
    fclose(f);
}
void w(int i) {
    FILE *f = fopen("tmp", "w");
    fprintf(f, "%d", i );
    fclose(f);
    sync();
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        w(i);
        sleep(1);
        r();
    }
}