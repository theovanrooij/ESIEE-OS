#include <stdio.h>
#include "gestionFichiers.h"

int main (int argc, char *argv[]) {
    if (argc != 2){
        printf("Vous devez indiquer le fichier à lire.\n");
        return 0;
    }
    int descripteurFichier = open(argv[1],0);
    
    if (descripteurFichier == -1){
        printf("Le fichier n'a pas pu être ouvrir.\n");
        return 0;
    }
    char* ligne = litLigne(descripteurFichier);
    printf("%s\n",ligne);
    int closeValue = close(descripteurFichier);
    return 0;
}