#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "exo1.h"
#include "../TDm1/gestionFichiers.h"
#include <errno.h>  

int main(){
    pid_t fils_pid = fork();
    int exec;
    char buffer[ 256 ];
    int descripteurFichier;
    char* ligne;

    descripteurFichier = open("texte.txt",0);
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

///////////////////// VERSION DE TEST
// int main(){
//     pid_t fils_pid = fork();
//     int exec;
//     char buffer[ 256 ];
//     char* argv[2];
//     argv[0] = "";
//     argv[1] = "./texte.txt";
//     if(fils_pid ==0){
//         // Comme le comportement attendu est le même que ce programme
//         exec = execvp("../TDm1/2b2",argv);
//         if(exec == -1) {
            
//             strerror_r( errno, buffer, 256 ); // get string message from errno, XSI-compliant version
//             printf("Error fils %s \n", buffer);
//         }

//     } else if (fils_pid > 0) {
//         wait(NULL);
//         exec = execvp("../TDm1/2b2",argv);
//         if(exec == -1) {
            
//             strerror_r( errno, buffer, 256 ); // get string message from errno, XSI-compliant version
//             printf("Error %s\n", buffer);
//         }
        
//     }
//     return 0;
// } 