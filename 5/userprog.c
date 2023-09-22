#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/syscall.h>
#include <string.h>
int main(void)
{
    long return_value = syscall(434);

    printf("return value from syscall: %ld, erron:%d\n", return_value, errno);
    return 0;
}
