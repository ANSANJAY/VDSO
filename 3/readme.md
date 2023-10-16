asmlinkage
---------------

When you compile a program the compiler's optimizer will occasionally put a function's parameters in registers instead of putting them on the program's stack

This optimization works because the compiler is emitting code for both the caller and the callee and so both sides are made aware of this slight-of-hand

This will not work for the kernel.

asmlinkage is #define for some gcc magic that tells the compiler that the function should not expect to find any of its arguments in registers (a common optimization), but only on the CPU's stack

The actual implementation of asmlinkage is architecture-specific

For example, on x86_64 these markers do nothing

on x86_32 asmlinkage expands to extern "C" __attribute__((regparm(0)))

From x86/include/linux/linkage.h file

#ifdef CONFIG_X86_32
#define asmlinkage CPP_ASMLINKAGE __attribute__((regparm(0)))
#endif /* CONFIG_X86_32 */

From linux/linkage.h file
#ifdef __cplusplus
#define CPP_ASMLINKAGE extern "C"
#else
#define CPP_ASMLINKAGE
#endif

#ifndef asmlinkage
#define asmlinkage CPP_ASMLINKAGE
#endif

our asmlinkage (3, ret, fd, buf, count); expands to:

    __asm__ __volatile__ ("" : "=r" (ret) : "0" (ret), "m" (fd), "m" (buf), "m" (count));

The gcc docs for the regparm (number) attribute say "On the Intel 386, the regparm attribute causes the compiler to pass arguments number one to number on the stack."

The template is empty, so no actual assembly is inserted, but the presence of the operands prevents the C compiler from doing any unwanted optimizations. In particular, the output operand ret has a constraint that it should be in a register ("=r"), and the other input registers (fd, buf, count) are memory operands ("m").
