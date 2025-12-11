#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    __pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE); // exit process
    }
    else if (pid == 0)
    {
        // chiled process
        printf("Hello, from chilled process with pid: %d ", getpid());
        sleep(2);
        // print and exit after 10 sec
        printf("Parent ppid %d\n", getppid());
        exit(EXIT_SUCCESS); // return (exit_code * 256) to parent, EXIT_SUCCESS = 0
    }
    else
    {
        // parent process
        printf("Hello, from parent process with pid: %d\n", getpid());
        printf("Waiting chiled process until finished ....\n");
        // wait for the null process to complete
        int status;
        wait(&status); // expected 0 from chilled
        printf("%d\n", status);
    }
    // while(1);
    return 0;
}
