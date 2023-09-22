#define SYSCALL_DEFINE0(sname)                                  \
        SYSCALL_METADATA(_##sname, 0);                          \
        asmlinkage long sys_##sname(void);                      \
        ALLOW_ERROR_INJECTION(sys_##sname, ERRNO);              \
        asmlinkage long sys_##sname(void)

SYSCALL_DEFINE0(getpid)
{
	return 1;
}
