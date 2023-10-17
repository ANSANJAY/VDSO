**strace and vDSO** 🕵️‍♂️🔗
---

**1. Explain the technical concept:**

- **strace** is a diagnostic, debugging and instructional userspace utility for Linux. It's used to monitor interactions between processes and the Linux kernel, which are called system calls.

- **vDSO** (Virtual Dynamic Shared Object) optimizes the execution of specific system calls by avoiding a mode switch from user mode to kernel mode. Instead, it maps certain kernel functionalities as a shared library in the user-space.

- When you use `strace` to trace system calls, those handled by vDSO won't appear in the output because they aren't true "system calls" in the traditional sense. They are, effectively, local function calls within the process's address space.

- **ltrace**, on the other hand, is a tool that intercepts and records dynamic library calls made by a process. As vDSO is essentially a small shared library mapped into the user-space, using `ltrace` allows you to capture calls to system calls implemented via vDSO.

**2. Curious questions:**

- *Why wouldn't vDSO calls show up when using strace?*

  - **Answer**: `strace` monitors actual system calls where there's a switch from user mode to kernel mode. vDSO bypasses this switch by providing certain kernel functionalities directly in the user space. Hence, these aren't visible to `strace`.

- *How does ltrace differ from strace in terms of what they trace?*

  - **Answer**: While `strace` traces system calls made by a process, `ltrace` intercepts and logs dynamic library calls made by that process. Since vDSO is a shared library in the user-space, its calls can be traced by `ltrace`.

**3. Explain the concept in simple words:**

- Imagine watching a magician 🎩✨ perform. `strace` is like a camera that only captures when the magician interacts with an assistant outside the stage (like the kernel). So, if the magician performs a trick using an object he already had on stage (like vDSO in user space), the camera misses it. Now, `ltrace` is another camera that focuses on all the objects the magician uses on the stage. So, it captures tricks done with objects already present on stage. If you want to see every trick, you'd need to pay attention to both cameras!
