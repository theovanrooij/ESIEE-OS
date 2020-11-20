#include <unistd.h> 
#include <sys/wait.h>
#include <sys/types.h> 
#include "exo1.h"
#include <errno.h> 

int main(int argc, char *argv[]){
    pid_t fils_pid = fork();
    if(fils_pid ==0){
        afficheCourant("fils");
        affichePere("Vérification que le pid du père dans le fork est bien le meme que le courant avant fork.");
    } else if (fils_pid > 0) {
        afficheCourant("père");
        wait(NULL); // Ajout wait
    } else {
        perror("Fork n'a pas fonctionné");
    }
    return 0;
} 

// On constate que le père se termine avant le fils et donc afficheFils s'affiche das l'entrée stantard (comme si on voulait écrire dans le temrinal)