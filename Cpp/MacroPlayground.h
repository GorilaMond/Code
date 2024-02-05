#ifndef MACRO_PLAYGROUND_H
#define MACRO_PLAYGROUND_H

#include <string.h> // strerror
#include <errno.h>	// errno
#include <stdio.h>

// If cond is true, print format string ... and err infomation.
#define CHECK_ERR(cond, ...)                       \
	if (cond)                                      \
	{                                              \
		fprintf(stderr, "[%s] ", strerror(errno)); \
		fprintf(stderr, __VA_ARGS__);              \
		return -1;                                 \
	}

#define SHOW_AND_PARSE(...) \
    __VA_ARGS__;            \
    printf(#__VA_ARGS__ "\n");

#endif