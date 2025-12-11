#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    __pid_t pid;
    pid = fork();
    // fork(): return pid for chilled in parent if success and 0 in chilled, -1 in failure
    if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        printf("Hello, from chilled process with pid: %d ", getpid());
        printf("Parent ppid %d\n", getppid());

    }
    else
    {
        printf("Hello, from parent process with pid: %d\n", getpid());
    }
    return 0;
}
