#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

int main(){
    __pid_t pid = fork();
    if (pid == -1){
        return 1;
    }

    if (pid == 0){
        
        __pid_t p = getpid(); // only for security purposes so that I can kill the process from `top` if something goes wrong
        while(1){
            // infinit loop
            printf("(%d) printing for ever and ever...\n", p);
            usleep(5000);
        }
    } else {
        sleep(1);
        kill(pid, SIGKILL); // send a signal to kill the child process
        wait(NULL);
    }

}