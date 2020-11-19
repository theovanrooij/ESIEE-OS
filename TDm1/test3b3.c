#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "gestionFichiers.h"

int main (int argc, char *argv[]) {
    

    char* chaine ;
    int taille=0;
    
    while (1) {
        chaine = litLigne(0);
        taille = strlen(chaine);
        
        if (chaine[0] == 'q' && strlen(chaine) == 2){
            return 0;
        }
        writeLine(1,chaine);
    }
    return 0;
}

// Si je passe 1 en paramètre, rien ne se passe au niveau du system, a la place la chaine de caractère que l'on passe en paramètre est écrite dans le terminal.