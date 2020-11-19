#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "exo1.h"
#include "../TDm1/gestionFichiers.h"
#include <errno.h>  

int main(){
    pid_t fils_pid = fork();
    char buffer[ 256 ];
    int descripteurFichier;
    char* ligne;
    descripteurFichier = open("texte.txt",0);

    if(descripteurFichier == -1) {
        strerror_r( errno, buffer, 256 ); // get string message from errno, XSI-compliant version
        printf("Error %s\n", buffer);
        return 0;
    }

    if(fils_pid ==0){

        ligne = litLigne(descripteurFichier);
        writeLine(1,ligne);
        close(descripteurFichier);

    } else if (fils_pid > 0) {
        wait(NULL);
        ligne = litLigne(descripteurFichier);
        writeLine(1,"Papa : \n");
        writeLine(1,ligne);
        close(descripteurFichier);
        
    }
    return 0;
}