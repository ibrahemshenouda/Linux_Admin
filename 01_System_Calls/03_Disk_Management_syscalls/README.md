# 🎛️ Device I/O Control System Calls (`ioctl`)

This directory contains a C example demonstrating the usage of the **`ioctl` (Input/Output Control)** system call to interact with device driver controls (specifically terminal window attributes) and perform low-level standard input/output.

---

## 1. What is `ioctl()`?

Standard POSIX system calls like `read()` and `write()` perform stream-like byte transfers. However, physical devices have special configurations (like terminal dimensions, disk geometry, or network card speeds) that require custom control commands. 
*   **`ioctl`** is a generic system call that allows user-space programs to send device-specific control requests directly to kernel-space device drivers.

---

## 2. Terminal Size Retrieval (`ioctl_read_write.c`)

This program queries the properties of the active terminal emulator screen.

### Key Implementation Details
*   **`ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws)`**:
    *   `STDOUT_FILENO`: Standard output file descriptor (integer 1).
    *   `TIOCGWINSZ` (Terminal IOCtl Get WINdow SiZe): The specific control request command code.
    *   `&ws`: A pointer to a `struct winsize` structure, where the driver will write the active row and column pixel counts.
*   **Direct I/O Call usage**:
    *   Uses standard POSIX `read(STDIN_FILENO, ...)` and `write(STDOUT_FILENO, ...)` system calls directly instead of C library helpers (like `printf()` or `scanf()`).

### Compiling and Running
```bash
gcc ioctl_read_write.c -o ioctl_demo
./ioctl_demo
```
*(The terminal output will display your active window row/column sizes and echo back whatever string you type in response).*
