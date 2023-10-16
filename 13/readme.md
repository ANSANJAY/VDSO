Compatibility System Calls
------------------------------

Most 64-bit implementations of system calls work fine when the user space program is 32-bit

There are a couple of situations where a compatibility layer is needed to cope with size differences between 32-bit and 64-bit

This is needed whenever a system call argument is

	a pointer to a pointer
	a pointer to a struct containing a pointer (e.g. struct iovec __user *)
	a pointer to a varying sized integral type (time_t, off_t, long, ...)
	a pointer to a struct containing a varying sized integral type.

The second situation that requires a compatibility layer is if one of the system call’s arguments has a type that is explicitly 64-bit even on a 32-bit architecture, for example loff_t or __u64.

In this case, a value that arrives at a 64-bit kernel from a 32-bit application will be split into two 32-bit values, which then need to be re-assembled in the compatibility layer.

COMPAT_SYSCALL_DEFINEn
------------------------

The compatibility version of the system call is called compat_sys_xyzzy(), and is added with the COMPAT_SYSCALL_DEFINEn() macro, analogously to SYSCALL_DEFINEn

This version of the implementation runs as part of a 64-bit kernel, but expects to receive 32-bit parameter values and does whatever is needed to deal with them

Typically, the compat_sys_ version converts the values to 64-bit versions and either calls on to the sys_ version, or both of them call a common inner implementation function

The compat entry point also needs a corresponding function prototype, in include/linux/compat.h,

asmlinkage long compat_sys_xyzzy(...);

