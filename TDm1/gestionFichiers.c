#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> 

#define TAILLEBUFF 5000
char* litDixCaracteres(int descripteurFichier){
    char* chaine = (char*)malloc(10* sizeof(char));
    int i;
    
    int res = read(descripteurFichier, chaine,10);
   
    return chaine;
}
char* litLigne(int descripteurFichier){
    if (descripteurFichier < 0) {
        return NULL;
    }
    char* charLigne = (char*)malloc(1* sizeof(char));
    char* chaine = (char*)malloc((TAILLEBUFF+1)* sizeof(char));
    int i;
    int res;
    char retourLigne = '\n';
    char finChaine ='\0';
    for (i=0; i< TAILLEBUFF; i++) {
        res = read(descripteurFichier, charLigne,1);
        chaine[i]=charLigne[0];
        if(chaine[i]==retourLigne){
            chaine[i+1] = '\0';
            return chaine;
        }
            
    }
    
    // Si on a dépassé le buffer et qu'on a pas trouvé de caractère de fin 
    return NULL;
}

void writeLine(int descripteurFichier, char* line){
    int res = write(descripteurFichier,line,strlen(line));
}