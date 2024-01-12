#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>

// we define the number of the "users"
#define THREAD_NUM 16

sem_t semaphore;

void* routine(void* args){
    printf("(%d) Waiting in the login queue\n", *(int*)args);
    sem_wait(&semaphore);
    // start of "la section critique"
    printf("(%d) Logged in\n", *(int*)args);
    sleep(rand() % 5 + 1);
    printf("(%d) Logged out\n", *(int*)args);
    // end of "la section critique"
    sem_post(&semaphore);
    free(args);
}

int main(int argc, char *argv[]){
    pthread_t th[THREAD_NUM];
    // the server takes only 12 "users" at a time 
    // so the rest of them will be waiting for someone to logout
    sem_init(&semaphore, 0, 12);
    int i;
    // create the threads
    for(i=0; i< THREAD_NUM; i++){
        int* a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&th[i], NULL, &routine, a) != 0){
            perror("Failed to create thread\n");
        }
    }
    // wait for the threads to finish
    for(i=0; i< THREAD_NUM; i++){
        int* a = malloc(sizeof(int));
        *a = i;
        if(pthread_join(th[i], NULL) != 0){
            perror("Failed to join thread\n");
        }
    }
    sem_destroy(&semaphore);
    return 0;
}