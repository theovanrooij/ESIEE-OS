#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "../TDm1/gestionFichiers.h"
#include <errno.h>  

#define buff 5001

int main () {
    // Utilisation d"un tube car juste besoin de lire un petit message
    
    int pid1, pid2, x = 0, tube[2];
    pipe(tube);

    pid_t fils_pid = fork();
    char buffer[ 256 ]; // Pour les messages d"erreurs
    char* ligne;

    int descripteurFichier;

    if(fils_pid ==0){ // fils = process B
        descripteurFichier = open("Destination.txt",O_WRONLY| O_APPEND);
        if(descripteurFichier == -1) {
            strerror_r( errno, buffer, 256 ); // get string message from errno, XSI-compliant version
            printf("Error %s\n", buffer);
            return 0;
        }
        char message[buff];
        int readValue ;
        while (readValue = read(tube[0],message,buff) > 0) {
            writeLine(descripteurFichier,message);
        }
        if(readValue==-1){
            strerror_r( errno, buffer, 256 ); // get string message from errno, XSI-compliant version
            printf("Error fils %s\n", buffer);
        }
        
        close(descripteurFichier);

    } else if (fils_pid > 0) { // père = process A 

        descripteurFichier = open("Source.txt",0);
        if(descripteurFichier == -1) {
            strerror_r( errno, buffer, 256 ); // get string message from errno, XSI-compliant version
            printf("Error pere %s\n", buffer);
            return 0;
        }
        
        ligne = litLigne(descripteurFichier);
        while (ligne != NULL){ // Se termine quand meme car on ne trouve pas de retour à la ligne dans un fichier vide donc on retourne "null"
            
            if(write(tube[1],ligne,buff) == -1) {
                strerror_r( errno, buffer, 256 ); // get string message from errno, XSI-compliant version
                printf("Error pere %s\n", buffer);
            }
            ligne = litLigne(descripteurFichier); 
        }
        wait(NULL);
        close(descripteurFichier);
        
    }
    return 0;
}