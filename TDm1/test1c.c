#include <stdio.h>
#include "gestionFichiers.h"

int main (int argc, char *argv[]) {

    int descripteurFichier = open("text.txt",0);
    char* dixCaracteres = litDixCaracteres(descripteurFichier);
    printf("%s\n",dixCaracteres);
    int closeValue = close(descripteurFichier);

    return 0;
}