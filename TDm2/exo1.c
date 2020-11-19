#include <stdio.h>

void affichePere(char* chaine){
    printf("Processus Père : %d ; %s \n",getppid(),chaine);
}
void afficheCourant(char* chaine){
    printf("Processus : %d ; %s \n",getpid(),chaine);
}
void afficheBoth(char* chaine){
    printf("Processus Père : %d Processus : %d ; %s \n",getppid(),getpid(),chaine);
}
