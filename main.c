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
    printf("1. VOLD:DC");
    //char *command  = "VOLT:DC:RANG 7\n";
    char *command[50];
    //char *command = "VOLT:DC:RANG?\n";

    while(1==1){
        // Цикл
        int fd = open("/dev/usbtmc0", O_RDWR);
        gets(command);
        int szStr = strlen(command);
        //printf("Length is %d\n", szStr);
        write(fd, command,  szStr);
        write(fd, '\n', 1);

        ssize_t size = read(fd, &buf, 32);

        char x = buf[0];
        char y = buf[1];

        //printf("Read byte %d %d | %c %c\n", x, y , buf[0], buf[1]);
       // printf("Size %d\n", size);
        printf("==> %s \n\n", buf);


        close(fd);
    }
    return 0;
}
