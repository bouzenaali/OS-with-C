#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


int main(int argc, char *argv[]){
    int arr[] = {1, 2, 3, 4, 1, 2, 7, 4};
    int arrSize = sizeof(arr) / sizeof(int);
    int start, end;
    int fd[2];

    if(pipe(fd) == -1){
        printf("An error occurd with pipe\n");
        return 1;
    }

    int pid = fork();
    if (pid == 0) {
        start = 0;
        end = start + arrSize/2;
    } else {
        start = arrSize/2;
        end = arrSize;
    }

    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += arr[i];
    }

    printf("calculated partial sum: %d\n", sum);

    if (pid == 0) {
        close(fd[0]);
        write(fd[1], &sum, sizeof(int));
        close(fd[1]);
    } else {
        int sumOfChild;
        close(fd[1]);
        read(fd[0], &sumOfChild, sizeof(int));
        close(fd[0]);

        int total = sum + sumOfChild;
        printf("The total sum: %d",total);
        wait(NULL);
    }



    return 0;
}