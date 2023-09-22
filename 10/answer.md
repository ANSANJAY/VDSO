What happens when we compile the user space application for 32-bit will the code works?
========================================================================================

There are two 32-bit ABIs that can be supported by 64-bit x86 kernels, in addition to the native x86-64 ABI

The 32-bit ABIs are:

	1. The i386 ABI that emulates the ABI implemented by 32-bit x86 kernels.
	2. The x32 ABI that is a newer 32-bit ABI for x86-64 kernels.

gcc -m32 flag will generate code for the i386 ABI
gcc -mx32 flag will generate code for the x32 ABI.

The "syscall_64.tbl" file enumerates the system calls for the x86-64 and x32 ABIs:
The "64" entries are for the x64-64 ABI.
The "x32" entries are for the x32 ABI.
The "common" entries are for both the x64-64 and x32 ABI

The "syscall_32.tbl" enumerates the system calls for the i386 ABI.

For each system call number, the table lists two entry points:
	1.The entry point for 32-bit x86 kernels.
	2.The "compat" entry point for i386 ABI emulation on x86-64 kernels.

Some obsolete system calls that are no longer implemented by the kernel are listed without an entry point.

You need to add entry into arch/x86/entry/syscalls/syscall_32.tbl
434	i386	hello	sys_hello

Note: Applications using the x32 ABI won't run on systems with 32-bit kernels.
