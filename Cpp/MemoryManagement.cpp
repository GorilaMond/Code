#include <unistd.h>
#include <malloc.h>
#include <sys/mman.h>

void *_lb_loc_(void) {
    printf("malloc\n");
    return malloc(sizeof(int));
}
void *_lb_map_(void) {
    printf("mmap\n");
    return mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
}
void *_lb_new_(void) {
    malloc(1);
    auto a = new int[1111];
    sleep(1);
    return a;
}
main()
{
    void *arr[10];
    int i;
    for (i = 0; i < 5; i++)
    {
        sleep(1);
        arr[i] = _lb_loc_();
        *(int*)(arr[i]) = i;
    }
    for (; i < 10; i++)
    {
        sleep(1);
        arr[i] = _lb_map_();
        *(int*)(arr[i]) = i;
    }
    _lb_new_();
    for (i = 0; i < 5; i++)
    {
        sleep(1);
        free(arr[i]);
        printf("free\n");
    }
    for (; i < 10; i++)
    {
        sleep(1);
        munmap(arr[i], 4096);
        printf("munmap\n");
    }
    printf("test done\n");
}