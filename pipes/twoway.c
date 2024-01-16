#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


int main(int argc, char *argv[]){
    int p1[2]; // C => P
    int p2[2]; // P => C
    // p1[0] - read
    // p1[1] - write
    if (pipe(p1) == -1) { return 1; }
    if (pipe(p2) == -1) { return 1; }
    int pid = fork();
    if (pid == -1) { return 2; }

    if (pid == 0) {
        // child process
        close(p1[0]);
        close(p2[1]);
        int x;
        read(p2[0], &x, sizeof(int));
        printf("Child: Received %d\n", x);
        x *= 4;
        write(p1[1], &x, sizeof(int));
        printf("Child: Wrote %d\n", x);
        close(p1[1]);
        close(p2[0]);
    } else {
        // parent process
        close(p1[1]);
        close(p2[0]);
        srand(time(NULL));
        int y = rand() % 10;
        write(p2[1], &y, sizeof(int));
        printf("Parent: Wrote %d\n", y);
        read(p1[0], &y, sizeof(int));
        printf("Parent: Result is %d\n", y);
        wait(NULL);
        close(p2[1]);
        close(p1[0]);
    }


    return 0;
}

// explanation:
// when using a two directional data streams we need to use two pipes 
// one (P => C) and another (C => P) 