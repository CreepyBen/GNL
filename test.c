#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int     fd;
    char    buf[256];
    int     chars_read;

    fd = open("file.txt", O_RDONLY);
    while((chars_read = read(fd, buf, 8)))
    {
        if(fd < 0)
        {
            printf("Err: No file found.\n");
            break;
        }
        buf[chars_read] = '\0';
        printf("buf: %s\n", buf);
    }
}