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



#define TAILLEBUFF 5000


char* c;
int end;

char buffer[ 256 ]; // Pour les messages d"erreurs
sem_t lectureSem, ecritureSem;

void *lecture(void *inutilise) {
    // On ouvre Source et on l'écrit dans c
    int descripteurFichier1;
    descripteurFichier1 = open("Source.txt",0);
    if(descripteurFichier1 == -1) {
        strerror_r( errno, buffer, 256 ); // get string message from errno, XSI-compliant version
        printf("Error pere %s\n", buffer);
        return 0;
    }
    
    while(1) {
        // On attend de pouvoir écrire
        sem_wait(&ecritureSem);
        c = litLigne(descripteurFichier1);
        if (c == NULL) {
            end = 1;
            sem_post(&lectureSem);
            pthread_exit(NULL);
        }
        sem_post(&lectureSem);
    }
    pthread_exit(NULL);
}

void *ecriture(void *inutilise) {
    // J'ouvre destination et je recopie le contenu de la variable
    int descripteurFichier2;
    descripteurFichier2 = open("Destination.txt",O_WRONLY);
    if(descripteurFichier2 == -1) {
        strerror_r( errno, buffer, 256 ); // get string message from errno, XSI-compliant version
        printf("Error %s\n", buffer);
        return 0;
    }

    while(1) {
        sem_wait(&lectureSem);
        if (end == 1 ){
            pthread_exit(NULL);
        }
        writeLine(descripteurFichier2,c);
        sem_post(&ecritureSem);
    } 

    pthread_exit(NULL);
}
int main () {

    // Utilisation d"un tube car juste besoin de lire un petit message

    pthread_t thA, thB;
    sem_init(&lectureSem,PTHREAD_PROCESS_SHARED,0);
    sem_init(&ecritureSem,PTHREAD_PROCESS_SHARED,1);

    pthread_create(&thA, NULL, lecture, NULL);
    pthread_create(&thB, NULL, ecriture, NULL);
    pthread_join(thA,NULL);
    pthread_join(thB,NULL);
    return 0;
}

// Pb de synchro si non utilisation de sémaphore