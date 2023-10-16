System call which accepts a string argument, logs it on the kernel buffer
-----------------------------------------------------------------------------

As our system call has one argument, we use SYSCALL_DEFINE1, and our only parameter is a char * which we name string

Step1: Update my_syscalls/hello.c file

SYSCALL_DEFINE1(hello_str, const char __user *, string){
        char user_msg[256];
	pr_info("%s\n", __func__);
        long copied = strncpy_from_user(user_msg, string, sizeof(user_msg));
        if (copied < 0 || copied == sizeof(user_msg))
                return -EFAULT;
        pr_info("%s\n",user_msg);
        return 0;
}

We are using strncpy_from_user, since we cannot directly access user space memory in kernel space

strncpy_from_user behaves like normal strncpy, but checks the user-space memory address first.

If the string was too long or if there was a problem copying, we return EFAULT

Step2: Update system call table

Step3: Update include/linux/syscalls.h file

Step4: Compile and install the kernel
