#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include "exo1.h"

int main(int argc, char *argv[]){
    pid_t fils_pid = fork();
    if(fils_pid ==0){
        afficheCourant("fils");
    } else if (fils_pid > 0) {
        afficheCourant("père");
    } else {
        perror("Fork n'a pas fonctionné");
    }
    return 0;
} 