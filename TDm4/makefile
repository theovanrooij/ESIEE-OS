all: IA II clean

IA: IA.o gestionFichiers.o
	gcc  IA.o gestionFichiers.o -lpthread -o IA
	
IA.o: IA.c ../TDm1/gestionFichiers.h ../TDm1/gestionFichiers.c
	gcc -lpthread -c  IA.c

II: II.o 
	gcc  II.o -lpthread -o II
	
II.o: II.c 
	gcc -lpthread -c  II.c

gestionFichiers.o: ../TDm1/gestionFichiers.c ../TDm1/gestionFichiers.h
	gcc -c ../TDm1/gestionFichiers.c

clean:
	rm -rf *.o