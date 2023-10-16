Return value of system calls
----------------------------

Returning 0,  notifies the calling process that the system call succeeded and that no errors occurred

Returning errors: a negated value from the <errno.h> header file should be returned, indicating what type of error occurred

The system C library will automatically take that negative value and put the appropriate value in the errno variable in user-space (and return -1 from the function).

