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

    if (gettimeofday(&current_time, NULL) == -1)
        printf("gettimeofday");

    //look at /proc/pid/maps
    getchar();

    exit(EXIT_SUCCESS);
}
