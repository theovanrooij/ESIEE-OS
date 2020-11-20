#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "exo1.h"
#include "../TDm1/gestionFichiers.h"
#include <errno.h>  

int main (int argc, char *argv[]) {
    if (argc != 2){
        printf("Vous devez indiquer le fichier à lire.\n");
        return 0;
    }
    int descripteurFichier = open(argv[1],0);
    
    pid_t fils_pid = fork();
    char buffer[ 256 ];
    char* ligne;

    if(descripteurFichier == -1) {
        strerror_r( errno, buffer, 256 ); // get string message from errno, XSI-compliant version
        printf("Error %s\n", buffer);
        return 0;
    }

        ligne = litLigne(descripteurFichier);
        writeLine(1,ligne);
        close(descripteurFichier);
    return 0;
}