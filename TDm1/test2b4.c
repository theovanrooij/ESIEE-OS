#include <stdio.h>
#include <string.h>
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
    int nbLignes = 0;
    while (strcmp(ligne,"null") != 0){ // Se termine quand meme car on ne trouve pas de retour à la ligne dans un fichier vide donc on retourne "null"
        nbLignes++;
        ligne = litLigne(descripteurFichier);
    }
    printf("Le fichier contient %d lignes.\n",nbLignes);
    int closeValue = close(descripteurFichier);
    return 0;
}