Tracing Read System Call
--------------------------

Implemented in fs/read_write.c

SYSCALL_DEFINE3(read, unsigned int, fd, char __user *, buf, size_t, count)

SYSCALL_DEFINEn()
--------------------

SYSCALL_DEFINEn is a family of macros that make it easy to define a system call with N arguments.

n suffix indicates the argument count.

Eg: Use SYSCALL_DEFINE0 when no arguments are needed for system calls
    Use SYSCALL_DEFINE1 when system call has one argument

Definition: <linux/syscalls.h>

The SYSCALL_DEFINEn() macros initially give two distinct chunks of code

    SYSCALL_METADATA(_read, 3, unsigned int, fd, char __user *, buf, size_t, count)
    __SYSCALL_DEFINEx(3, _read, unsigned int, fd, char __user *, buf, size_t, count)
    {

The first part provides metadata about the syscall for tracing purposes
    It's only expanded when CONFIG_FTRACE_SYSCALLS is defined for the kernel build,

The __SYSCALL_DEFINEx() part is more interesting, as it holds the system call implementation.

