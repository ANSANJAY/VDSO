How come userspace reaches sys_read
--------------------------------------

We know system calls are identified by system call number.

System call table is where mapping between system call number and the entry point of system call is present

System call table for x86_64: arch/x86/entry/syscalls/syscall_64.tbl

Format of this file is as follows:

<number> <abi> <name> <entry point>

number: 	All syscalls are identified by a unique number.
abi:		common, 64, x32
	The "common" indicates that this system call is to be useable in either 32-bit or 64-bit x86 programs
name:		name of the system call
entry point:	the name of the function to call in order to handle the syscall.
