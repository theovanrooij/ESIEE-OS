#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/wait.h>
#include "exo1.h"

int main(int argc, char *argv[]){
    pid_t fils_pid = fork();
    if(fils_pid ==0){
        execvp("./testIB1",NULL);// Le père du nouveau a le meme pid que le programme actuel, c'est le comportement attendu.
    } else if (fils_pid > 0) {
        afficheCourant("Je suis le père.");// 1 processus
        wait(NULL); // Ajout wait
    }
    return 0;
} 