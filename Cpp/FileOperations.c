#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define _4K (4 >> 10)
int main(void)
{
	char buff[_4K];

	printf("[Enter] to test open...");
	getchar();
	int fd = open("open.c", O_RDWR | O_APPEND);

	printf("[Enter] to test read...");
	getchar();
	read(fd, buff, _4K);

	printf("[Enter] to test write...");
	getchar();
	write(fd, "\n", 1);
	sync();
	fsync(fd);

	printf("[Enter] to test close...");
	getchar();
	close(fd);

	printf("[Enter] to test return...");
	getchar();
	return 0;
}
