#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("I am the process p1 THE PARENT\n");
    // here we are at the parent process
    int id1 = fork();

    if (id1 == 0){
        // here we are at the first child (first gen) 
        printf("I am the process p2 SON OF p1\n");

        int id2 = fork();

        if (id2 == 0){
            // here we are at the first child (second gen)
            printf("I am the process p4 SON OF p2\n");
        } 
    } else {
        // still at the parent process

        int id3 = fork();

        if (id3 == 0){
            // here we are at the second child (first gen)
            printf("I am the process p3 SON OF p1\n");
            int id4 = fork();

            if (id4 == 0){
                // here we are at the second child (sencod gen)
                printf("I am the process p5 SON OF p3\n");   
            }
        } 
    };
    return 0;
}