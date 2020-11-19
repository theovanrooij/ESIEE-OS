#include <stdio.h>
#include "gestionFichiers.h"

int main (int argc, char *argv[]) {

    int descripteurFichier = open("text.txt",0);
    char* ligne = litLigne(descripteurFichier);
    printf("%s\n",ligne);
    int closeValue = close(descripteurFichier);
    return 0;
}