Generic System Call Table
--------------------------

Some architectures (e.g. x86) have their own architecture-specific syscall tables

Several other architectures share a generic syscall table.

For your system call to be used by multiple architectures.

Add your new system call to the generic list by adding an entry to the list in include/uapi/asm-generic/unistd.h

#define __NR_hello 434
__SYSCALL(__NR_hello, sys_hello)

Also update the __NR_syscalls count to reflect the additional system call

#define __NR_syscalls 435
