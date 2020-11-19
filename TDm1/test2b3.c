#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "gestionFichiers.h"

int main (int argc, char *argv[]) {

    int descripteurFichier = open("text.txt",0);
    char* ligne = litLigne(descripteurFichier);
    while (ligne != NULL){ // Se termine quand meme car on ne trouve pas de retour à la ligne dans un fichier vide donc on retourne "null"
        writeLine(1,ligne);
        ligne = litLigne(descripteurFichier);
    }
    int closeValue = close(descripteurFichier);
    return 0;
}