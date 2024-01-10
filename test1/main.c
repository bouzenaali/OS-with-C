#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

pthread_t t1;
pthread_t t2;

void affiche_A(){
    for (int i=1; i<=10; i++){
        printf("A");
    }
}

void affiche_B(){
    for (int i=1; i<=10; i++){
        printf("B");
    }
}

int main(){
    // creating the threads t1 and t2
    pthread_create(&t1, NULL,affiche_A, NULL);
    pthread_create(&t2, NULL,affiche_B, NULL);

    // Wait for the threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}