#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("I am the process p1 THE PARENT\n");
    int id1 = fork();

    if (id1 == 0){
        printf("I am the process p2 SON OF p1\n");

        int id2 = fork();

        if (id2 == 0){
            printf("I am the process p4 SON OF p2\n");
        } 
    } else {
        printf("I am the process p3 SON OF p1\n");

        int id3 = fork();

        if (id3 == 0){
            printf("I am the process p5 SON OF p3\n");
        } 
    };
    return 0;
}