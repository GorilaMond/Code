#include <stdio.h>    // printf
#include <fcntl.h>    // open
#include <unistd.h>   // close
#include <string.h>   // memset
#include <errno.h>    // errno
#include <stdlib.h>   // atoi
#include <sys/mman.h> // mmap
#include <sys/time.h> // gettimeofday

#include "MacroPlayground.h" // CHECK_ERR

#define FILE_SIZE (1u << 31)
#define PAGE_SIZE (4u << 10)
#define ROUND_NUM (5)

int main(int argc, char *argv[])
{
    printf("Size: 2G\n");
    printf("block/B\tmmap/s\tread/s\n");
    for (int r = 0; r < ROUND_NUM; r++)
    {
        for (int i = 1; i < argc; i++)
        {
            // mmap will read file content to memory, so it needs read permission
            int fd = open("TestFile.txt", O_RDWR); 
            CHECK_ERR(fd < 0, "Open failed.\n");

            int block = atoi(argv[i]);
            CHECK_ERR(block <= 0, "Arguments err.\n");
            printf("%d\t", block);

            char *buf = malloc(block);

            struct timeval tv1, tv2;

            char *map = mmap(NULL, FILE_SIZE, PROT_WRITE, MAP_SHARED, fd, 0);
            CHECK_ERR(map == (void *)-1, "Mmap failed.\n");

            gettimeofday(&tv1, NULL);
            for (unsigned off = 0; off < FILE_SIZE; off += block)
            {
                memcpy(buf, map + off, block);
            }
            gettimeofday(&tv2, NULL);
            printf("%lf\t", tv2.tv_sec - tv1.tv_sec + (tv2.tv_usec - tv1.tv_usec) * 1e-6);
            
            munmap(map, FILE_SIZE);

            gettimeofday(&tv1, NULL);
            for (unsigned off = 0; off < FILE_SIZE; off += block)
            {
                read(fd, buf, block);
            }
            gettimeofday(&tv2, NULL);
            printf("%lf\n", tv2.tv_sec - tv1.tv_sec + (tv2.tv_usec - tv1.tv_usec) * 1e-6);

            close(fd);
        }
    }
    return 0;
}