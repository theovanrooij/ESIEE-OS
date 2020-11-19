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
    int descripteurFichier = open("text.txt",O_WRONLY| O_APPEND);//O_APPEND permet d'écrire à la fin du fichier
    writeLine(descripteurFichier,argv[1]);
    int closeValue = close(descripteurFichier);

    return 0;
}