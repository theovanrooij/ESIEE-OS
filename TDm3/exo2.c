#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "../TDm1/gestionFichiers.h"
#include <errno.h>  

static void action(int sig) {
    switch(sig){
        case SIGUSR1:
            kill(getpid(),SIGTERM);
        break;
        case SIGUSR2:

            writeLine(1,"Trop tard, coffre fermé\n");
            kill(getpid(),SIGTERM);
        break;
    }
}

int main () {

    // Installation des gestionnaires de signaux
    if(signal(SIGUSR1, action) == SIG_ERR)
        printf("Erreur de signal \n");
    if(signal(SIGUSR2, action) == SIG_ERR)
        printf("Erreur de signal\n");

    // Utilisation d"un tube car juste besoin de lire un petit message

    pid_t fils_pid = fork();
    char buffer[ 256 ]; // Pour les messages d"erreurs 
    strerror_r( errno, buffer, 256 ); // get string message from errno, XSI-compliant version
    printf("Error %s\n", buffer);
    
    if(fils_pid ==0){ // fils = process B | Compte 10 secondes
        int secondes = 0;
        while (secondes<10){
            sleep(1);
            secondes++;
        }
        kill(getppid(), SIGUSR2);
        return 0;
    } else if (fils_pid > 0) { // père = process A | Lit le code

    char* chaine ;
        while (1) {
        chaine = litLigne(0);

        if (strcmp(chaine,"1234\n") == 0){
            writeLine(1,"Bravo : coffre ouvert\n");
            kill(fils_pid, SIGUSR1);
            return 0;
        } else {
            writeLine(1,"Code faux : coffre-fort fermé\n");
        }
    }
        
    }
    return 0;
}