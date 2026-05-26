# 📂 File Management System Calls

This directory contains code examples implementing basic file input and output (I/O) operations using low-level POSIX system calls in C++ and standard high-level file utilities in Python.

---

## 1. POSIX System Calls (`file_mgmt.cpp`)

The C++ program demonstrates the direct usage of Linux kernel system calls for file manipulation. Unlike language-level standard libraries (like `<fstream>` or `<iostream>`), these calls talk directly to the OS Virtual File System (VFS).

### System Calls Used
*   **`open(filename, flags, mode)`**: Opens the file and returns a unique **File Descriptor (fd)** integer.
    *   *Flags*:
        *   `O_RDWR`: Opens the file in read-write mode.
        *   `O_CREAT`: Creates the file if it does not already exist.
        *   `O_TRUNC`: Truncates (deletes) all existing data in the file if it already exists.
    *   *Permissions (Mode)*:
        *   `S_IRUSR`: Read permission for the owner.
        *   `S_IWUSR`: Write permission for the owner.
*   **`write(fd, buffer, length)`**: Writes bytes from a memory buffer to the file descriptor offset.
*   **`lseek(fd, offset, whence)`**: Repositions the read/write file offset pointer. Here, `lseek(fd, 0, SEEK_SET)` resets the offset back to the beginning (`0` bytes from start) so we can read what we just wrote.
*   **`read(fd, buffer, length)`**: Reads bytes from the file descriptor into a character array.
*   **`close(fd)`**: Releases the file descriptor and flushes cache buffers.

### Compiling and Running
To compile and run the C++ program:
```bash
g++ file_mgmt.cpp -o file_mgmt_cpp
./file_mgmt_cpp
```

---

## 2. Python Implementation (`file_mgmt.py`)

The Python script shows a simpler, high-level approach using Python's built-in file handlers, which abstract the underlying system calls.

*   Uses the Python `with open(..., 'w') as file:` block, which automatically closes the file descriptor when execution exits the block.
*   Implements error handling using `try...except IOError` block to catch read/write device failures.

### Running
To run the Python script:
```bash
python3 file_mgmt.py
```
