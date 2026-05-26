# ⚙️ Process Control System Calls

This directory contains C code examples demonstrating the three foundational system calls used for process lifecycle management in Unix-like operating systems: process cloning (`fork`), process replacement (`exec`), and process synchronization (`wait` and `exit`).

---

## 1. Process Cloning (`fork.c`)

The `fork()` system call is used to create a new process (the child process) by duplicating the calling process (the parent process). 

### Key Concepts
*   **Dual Execution**: After `fork()`, both parent and child processes execute the next instruction concurrently.
*   **Return Values**:
    *   `pid < 0`: Fork failed (system out of memory/PID limit).
    *   `pid == 0`: Code executed inside the **child** process.
    *   `pid > 0`: Code executed inside the **parent** process (value is the child's PID).
*   **Identification**:
    *   `getpid()`: Returns the process's own PID.
    *   `getppid()`: Returns the Parent's Process ID.

### Compiling and Running
```bash
gcc fork.c -o fork_demo
./fork_demo
```

---

## 2. Process Image Replacement (`exec.c`)

The `exec()` family of functions (specifically `execvp` here) replaces the current process stack, heap, code, and data segments with a new executable program image.

### Key Concepts
*   **No Return**: If `execvp()` is successful, it **never returns** to the calling code because the original code no longer exists in memory. The program immediately starts running the new command (in this case, `/bin/ls -l`).
*   **Arguments**: Takes the command name and an array of argument string pointers (terminated by `NULL`).

### Compiling and Running
```bash
gcc exec.c -o exec_demo
./exec_demo
```

---

## 3. Synchronization & Exit Status (`wait_and_exit.c`)

This example demonstrates how parent and child processes coordinate execution timing and communicate exit return codes.

### Key Concepts
*   **`exit(code)`**: Terminates the active process. An exit code of `0` (or `EXIT_SUCCESS`) indicates successful completion, while non-zero values indicate errors.
*   **`wait(&status)`**: Blocks the parent process's execution until one of its child processes terminates. It reaps the child process, preventing it from remaining a "Zombie" process in the kernel table.
*   **Exit Status representation**: The `status` integer contains both the exit code and signal termination info. The exit code is encoded in the higher 8 bits (multiplied by 256).

### Compiling and Running
```bash
gcc wait_and_exit.c -o wait_demo
./wait_demo
```
