#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "gestionFichiers.h"

int main (int argc, char *argv[]) {

    if (argc != 2){
        printf("Que souhaitez-vous écrire ?\n");
        return 0;
    }
    writeLine(1,argv[1]);

    return 0;
}

// Si je passe 1 en paramètre, rien ne se passe au niveau du system, a la place la chaine de caractère que l'on passe en paramètre est écrite dans le terminal.