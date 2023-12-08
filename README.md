# get_next_line

<p align="center">
    <img src="./printscreen.png"/>
</p>

<p align="center">This project is about reading from a file descriptor and returning always the next line, using the read function and a static variable.</p>
---

### File descriptor
File descriptors are unique identifiers for files so that a process can interact with them. Each process has an individual file descriptor table, so a single file will probably have different file descriptors for different processes. With the file descriptor, we can perform actions like read and write on the file that corresponds to the file descriptor.

### Read
The read function from `unistd.h` library allows us to read the content of a file, into our C code through the file descriptor. This function takes three arguments:
- The file descriptor itself.
- The buffer: A slice of memory where the bytes read from the function will be stored (usually a char vector you malloc)
- The Buffer_Size: The amount of bytes that will be read from the file.

The buffer_size is the one we have to understand better. The goal of not reading the whole file in a single use of the function is that we do not consume too much memory loading a gigantic file in RAM all at once; instead,  we read a few bytes, manipulate them as we wish, and then read again, and again, and again, a piece by piece.

It is also important to remember that when we use a file descriptor in the read function, we start reading from where we stopped on the last use of `read`, for example, if we read 10 characters at first, when we call read again (depending on whether it is in the same scope, same function, or same file) in the same file descriptor, we will get ANOTHER 10 bytes, starting from the 11th byte of the first read.

### Static variables
A static variable is a very simple concept: A static variable preserves its value beyond its scope. For example:
```c
#include <stdio.h>

void add_up()
{
    int non_static_var = 0;
    static int static_var = 0;

    non_static_var++;
    static_var++;
    printf("non static: %i\n", non_static_var);
    printf("static: %i\n", static_var);
}

int main()
{
    add_up(); //output will be non static: 1 and static: 1
    add_up(); //output will be non static: 1 and static: 2
    add_up(); //output will be non static: 1 and static: 3
}
```
We can observe that the non-static variable always gets reset to 0 when the `add_up()` function is called again because it is tied to its scope, and the static variable always maintains its value.
