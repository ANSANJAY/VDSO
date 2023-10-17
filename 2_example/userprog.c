#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	struct timeval current_time;
	unsigned int loop;
	int i;

	if (argc < 2 || strcmp(argv[1], "--help") == 0)
		printf("%s loop-count\n", argv[0]);

	loop = atoi(argv[1]);

	for (i = 0; i < loop; i++) {
		if (gettimeofday(&current_time, NULL) == -1)
			printf("gettimeofday");
	}

	exit(EXIT_SUCCESS);
}
