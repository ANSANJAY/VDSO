Adding a New System Call
==============================

System Call which do not accept any arguments
-------------------------------------------------

1. cd <linux_source>

2. Create a directory named 'my_syscalls' and change the directory to 'my_syscalls'

$ mkdir my_syscalls
$ cd my_syscalls

3. Create a file 'hello.c' using your favourite editor

$ vi hello.c

#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(hello) {
    printk("Hello, world!\n");
    return 0;
}

4. Create a 'Makefile' in the 'my_syscalls' directory.

$ vi Makefile

obj-y := hello.o

This is to ensure that the hello.c file is compiled and included in the kernel source code.


5. Add 'my_syscalls' to kernel Makefile

$ cd ..

search for core-y,  you’ll find this line as the second instance of your search:

core-y          += kernel/ certs/ mm/ fs/ ipc/ security/ crypto/ block/

Add 'my_syscalls' here

core-y          += kernel/ certs/ mm/ fs/ ipc/ security/ crypto/ block/ my_syscalls

6. Add the new system call to the system call table

$ vi arch/x86/entry/syscalls/syscall_64.tbl

434     common  hello                   __x64_sys_hello

7. Add new system call to the system call header file

vi include/linux/syscalls.h

asmlinkage long sys_hello(void);

8. Compile and Install the kernel

$ make

$ make modules_install

$ make install

Look at system.map and /proc/kallsyms for sys_hello



