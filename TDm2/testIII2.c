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

int main(){
    int descripteurFichier = open("texte.txt",0);
    char buffer[ 256 ];
    char* ligne;
    if(descripteurFichier == -1) {
        strerror_r( errno, buffer, 256 ); // get string message from errno, XSI-compliant version
        printf("Error %s\n", buffer);
        return 0;
    }
    pid_t fils_pid = fork();
    
   
    ligne = litLigne(descripteurFichier);
    
    close(descripteurFichier);
    printf("%s",ligne);
    free(ligne);

    return 0;
}