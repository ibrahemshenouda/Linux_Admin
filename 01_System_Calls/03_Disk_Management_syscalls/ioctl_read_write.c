#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

int main()
{
    // winsize : struct builtin ioctl.h contains ws_row, ws_col, ws_xpixel, ws_ypixel
    struct winsize ws;
    // TIOCGWINSZ: Terminal IOCtl Get WINdow SiZe, request type
    // STDOUT_FILENO : fd out
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1)
    {
        perror("ioctl");
        return 1;
    }

    char msg[100];
    sprintf(msg, "Terminal Size: Rows=%d, Cols=%d\nType something: ", ws.ws_row, ws.ws_col);
    write(STDOUT_FILENO, msg, strlen(msg));

    char buffer[50];
    int bytes = read(STDIN_FILENO, buffer, sizeof(buffer));

    if (bytes > 0)
    {
        write(STDOUT_FILENO, "You typed: ", 11);
        write(STDOUT_FILENO, buffer, bytes);
    }

    return 0;
}