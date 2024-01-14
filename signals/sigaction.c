#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <bits/sigaction.h>
#include <asm-generic/signal-defs.h>

void handle_sigstp(int sig){
    printf(" STOP is not allowed\n");
}

void handle_sigcont(int sig){
    printf("Input number: ");
    fflush(stdout);
}

int main(int argc, char *argv[]){

    struct sigaction sa;
    sa.sa_handler = &handle_sigcont;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGCONT, &sa, NULL);

    // struct sigaction sa;
    // sa.sa_handler = &handle_sigstp;
    // sa.sa_flags = SA_RESTART;
    // sigaction(SIGTSTP, &sa, NULL);

    // OR simply us signal()
    // signal(SIGTSTP, &handle_sigstp);
    
    int x;
    printf("Input number: ");
    scanf("%d", &x);
    printf("Result %d * 5 = %d", x, x*5);

    return 0;
}
