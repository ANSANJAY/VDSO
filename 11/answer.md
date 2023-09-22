How is __ia32_sys_hello map to __x64_sys_hello
-----------------------------------------------

In arch/x86/include/asm/syscall_wrapper.h, SYSCALL_DEFINE0 creates an alias for the real 64-bit application

/*
 * To keep the naming coherent, re-define SYSCALL_DEFINE0 to create an alias
 * named __ia32_sys_*()
 */
#define SYSCALL_DEFINE0(sname)					\
	SYSCALL_METADATA(_##sname, 0);				\
	asmlinkage long __x64_sys_##sname(void);		\
	ALLOW_ERROR_INJECTION(__x64_sys_##sname, ERRNO);	\
	SYSCALL_ALIAS(__ia32_sys_##sname, __x64_sys_##sname);	\
	asmlinkage long __x64_sys_##sname(void)
