/*
 * TRIG:SOUR?
 *
 *
 * //
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char byte;
    char *buf[32];

    int i;
    for(i=0;i<32;i++) {
        buf[i] = 0;
    }

    printf("Scanner. Select Parameter:\n");
    printf("READ? 10 times.\n");

    char *command[50];
    char cmd[] = "READ?";

    int R = 10; // R - Range
    int szStr = strlen(command);

    for (i=0; i<R; i++){

        int fd = open("/dev/usbtmc0", O_RDWR);


        write(fd, cmd,  szStr);
        write(fd, '\n', 1);

        ssize_t size = read(fd, &buf, 32);
        printf("> %s \n", buf);

        close(fd);
    }
    return 0;
}
