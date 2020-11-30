#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "../TDm1/gestionFichiers.h"
#include <errno.h>  
#include <pthread.h>
#include<semaphore.h>

sem_t S1, S2, S3;
void *P1(void *inutilise) {
    int j;
    int i=1;
    for(j = 0; j < 10; j++){
        sem_wait(&S1);
        printf("Affichage %d du thread %d\n", j+1, i); // Thread Pi avec i = 1, 2, 3
        sem_post(&S2);
    }
}

void *P2(void *inutilise) {
    int j;
    int i=2;
    for(j = 0; j < 10; j++){

        sem_wait(&S2);
        printf("Affichage %d du thread %d\n", j+1, i); // Thread Pi avec i = 1, 2, 3
        sem_post(&S3);
    }
}

void *P3(void *inutilise) {
    int j;
    int i = 3;
    for(j = 0; j < 10; j++){
        sem_wait(&S3);
        printf("Affichage %d du thread %d\n", j+1, i); // Thread Pi avec i = 1, 2, 3
        sem_post(&S1);
    }
        
}
int main () {

    // Utilisation d"un tube car juste besoin de lire un petit message

    pthread_t th1, th2, th3;
    sem_init(&S1,PTHREAD_PROCESS_SHARED,1);
    sem_init(&S2,PTHREAD_PROCESS_SHARED,0);
    sem_init(&S3,PTHREAD_PROCESS_SHARED,0);

    pthread_create(&th1, NULL, P1, NULL);
    pthread_create(&th2, NULL, P2, NULL);
    pthread_create(&th3, NULL, P3, NULL);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    pthread_join(th3,NULL);
    return 0;
}

// Principe de l'exo d'avant. 3 sémaphore. le thread 1 s'affiche après down(S1) puis UP(S2). T2 wait (S2) affiche UP(S3) ...