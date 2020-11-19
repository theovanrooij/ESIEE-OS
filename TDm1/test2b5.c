#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "gestionFichiers.h"

int main (int argc, char *argv[]) {

    char* ligne = litLigne(0);
    while (strcmp(ligne,"null") != 0){ // Se termine quand meme car on ne trouve pas de retour à la ligne dans un fichier vide donc on retourne "null"
        printf("%s",ligne); // Pas demandé , pour voir ce que ça fait
        ligne = litLigne(0);
    }
    return 0;
}

// En passant 0 en paramètre ca lit l'entrée standard (le terminal) 