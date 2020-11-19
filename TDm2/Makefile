all:	testIB1 testIB2 testIB3 exo2 III1 III2 III3 clean

testIB1: exo1.o testIB1.o
	gcc exo1.o testIB1.o -o testIB1
	
testIB1.o: exo1.h exo1.c testIB1.c
	gcc -c testIB1.c
	
testIB2: exo1.o testIB2.o
	gcc exo1.o testIB2.o -o testIB2
	
testIB2.o: exo1.h exo1.c testIB2.c
	gcc -c testIB2.c

testIB3: exo1.o testIB3.o
	gcc exo1.o testIB3.o -o testIB3
	
testIB3.o: exo1.h exo1.c testIB3.c
	gcc -c testIB3.c

exo2: exo1.o exo2.o
	gcc exo1.o exo2.o -o exo2
	
exo2.o: exo1.h exo1.c exo2.c
	gcc -c exo2.c

III1: exo1.o testIII1.o gestionFichiers.o
	gcc exo1.o testIII1.o gestionFichiers.o -o III1
	
testIII1.o: exo1.h exo1.c testIII1.c ../TDm1/gestionFichiers.h ../TDm1/gestionFichiers.c
	gcc -c testIII1.c

III2: exo1.o testIII2.o gestionFichiers.o
	gcc exo1.o testIII2.o gestionFichiers.o -o III2
	
testIII2.o: exo1.h exo1.c testIII2.c ../TDm1/gestionFichiers.h ../TDm1/gestionFichiers.c
	gcc -c testIII2.c

III3: exo1.o testIII3.o gestionFichiers.o
	gcc exo1.o testIII3.o gestionFichiers.o -o III3
	
testIII3.o: exo1.h exo1.c testIII3.c ../TDm1/gestionFichiers.h ../TDm1/gestionFichiers.c
	gcc -c testIII3.c

exo1.o: exo1.c exo1.h
	gcc -c exo1.c

gestionFichiers.o: ../TDm1/gestionFichiers.c ../TDm1/gestionFichiers.h
	gcc -c ../TDm1/gestionFichiers.c

clean:
	rm -rf *.o