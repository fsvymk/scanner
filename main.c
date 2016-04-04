/*
 * TRIG:SOUR?
 *
 *
 * //
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <a.out.h>
#include <unistd.h>

int main() {
    char byte;
    char *buf[32];

    int i;
    for(i=0;i<32;i++) {
        buf[i] = 0;
    }

    int R = 2000;
    printf("Scanner. Select Parameter:\n");
    printf("READ? %d times.\n",R);

    char *command[50];
    char cmd[] = "READ?";

    // R - Range
    int szStr = strlen(command);
    int status = 0; // not connected
    int work = 1; // false - pause.
    //for (i=0; i<R; i++){
    char hid;

    while(1==1)
    {
        //if(kbhit()) hid = getchar();
        //if(hid == 13) work = !work;
        //usleep(1000);

        int fd = open("/dev/usbtmc0", O_RDWR);

        // Connected
        if(fd!=-1 ){
            if(status!=fd){
                status = fd;
                printf("Connected.\n");
            }
            write(fd, cmd,  szStr);
            write(fd, '\n', 1);
            ssize_t size = read(fd, &buf, 32);
            printf("> %s \n", buf);

        // Disconnected
        }else
        {
            if(status!=fd){
                status =fd;
                printf("Disconnected.\n");
            }
            else{
                //printf(".");
            }
        }
        close(fd);
    }
    return 0;
}
