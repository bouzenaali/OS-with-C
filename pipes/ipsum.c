#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


int main(int argc, char *argv[]){
    int arr[] = {1, 2, 3, 4, 1, 2, 3};
    int fd[2];

    if(pipe(fd) == -1){
        printf("An error occurd with pipe\n");
        return 1;
    }



    return 0;
}