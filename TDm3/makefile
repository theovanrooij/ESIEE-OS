all: IB1 exo2 clean

IB1: IB1.o gestionFichiers.o
	gcc  IB1.o gestionFichiers.o -o IB1
	
IB1.o: IB1.c ../TDm1/gestionFichiers.h ../TDm1/gestionFichiers.c
	gcc -c IB1.c

exo2: exo2.o gestionFichiers.o
	gcc  exo2.o gestionFichiers.o -o exo2
	
exo2.o: exo2.c ../TDm1/gestionFichiers.h ../TDm1/gestionFichiers.c
	gcc -c exo2.c

gestionFichiers.o: ../TDm1/gestionFichiers.c ../TDm1/gestionFichiers.h
	gcc -c ../TDm1/gestionFichiers.c

clean:
	rm -rf *.o