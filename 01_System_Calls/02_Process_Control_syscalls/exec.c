#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *const cmd[] = {"ls", "-l", NULL};

    /*exec(), execev(), execvp(), execlp() : The  exec()  family
    of functions replaces the current process image
    with a new process image*/

    execvp(cmd[0], cmd);
    // if execvp() ssuccess this proces terminated and will not continue here
    perror("Return from execvp() not expected");
    exit(EXIT_FAILURE);
}