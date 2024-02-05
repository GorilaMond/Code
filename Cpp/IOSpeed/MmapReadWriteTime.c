#include <fcntl.h> // open
#include <unistd.h> // close
#include <stdio.h>  // printf
#include <stdlib.h> // atoi
#include <sys/time.h> // gettimeofday
#include <sys/mman.h> // mmap

#include "MacroPlayground.h"

int main(int argc, char *argv[])
{
    printf("size/B\trw/s\tmmap/s\n");
    for (int ia = 1; ia < argc; ia++)
    {
        int n = atoi(argv[ia]) / sizeof(int);
        CHECK_ERR(n <= 0, "Arguments error...\n");
        size_t file_size = n * sizeof(int);
        printf("%ld\t", file_size);

        // init file
        int fd = open("MmapReadWriteTimeTestFile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
        CHECK_ERR(fd < 0, "Open failed when init...\n");
        int *buf = calloc(n, sizeof(int));
        CHECK_ERR(write(fd, buf, file_size) != file_size, "Initialize file failed...\n");
        free(buf);
        close(fd);

        struct timeval tv1, tv2;

        // read & write
        fd = open("MmapReadWriteTimeTestFile.txt", O_RDWR);
        CHECK_ERR(fd < 0, "Open failed when rw...\n");
        buf = malloc(file_size);
        gettimeofday(&tv1, NULL);
        CHECK_ERR(read(fd, buf, file_size) != file_size, "Read failed when rw...\n");
        for (int i = 0; i < n; ++i)
        {
            ++buf[i];
        }
        lseek(fd, 0, SEEK_SET);
        CHECK_ERR(write(fd, buf, file_size) != file_size, "Write failed when rw...\n");
        fdatasync(fd);
        gettimeofday(&tv2, NULL);
        printf("%lf\t", (tv2.tv_sec - tv1.tv_sec) + (tv2.tv_usec - tv1.tv_usec) * 1e-6);
        free(buf);
        close(fd);

        // mmap
        fd = open("MmapReadWriteTimeTestFile.txt", O_RDWR);
        CHECK_ERR(fd < 0, "Open failed when mmap...\n")
        buf = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        CHECK_ERR(buf == (void*)-1, "Mmap failed when mmap...\n");
        gettimeofday(&tv1, NULL);
        for (int i = 0; i < n; ++i)
        {
            ++buf[i];
        }
        msync(buf, file_size, MS_SYNC);
        gettimeofday(&tv2, NULL);
        printf("%lf\n", (tv2.tv_sec - tv1.tv_sec) + (tv2.tv_usec - tv1.tv_usec) * 1e-6);
        munmap(buf, file_size);
        close(fd);
    }

    return 0;
}