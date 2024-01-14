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
        while(1){
            // infinit loop
            printf("some output\n");
            usleep(5000);
        }
    } else {
        kill(pid, SIGSTOP);
        int t;
        do
        {
            printf("Time in seconds for execution: ");
            scanf("%d", &t);

            if (t > 0){
                kill(pid, SIGCONT);
                sleep(t);
                kill(pid, SIGSTOP);
            }
        } while (t > 0);

        kill(pid, SIGKILL);
        wait(NULL);
        
    }

    return 0;

}