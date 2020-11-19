all : 1c 2b1 2b2 2b3 2b4 2b5 3b1 3b2 3b3 clean

1c: gestionFichiers.o test1c.o
	gcc gestionFichiers.o test1c.o -o 1c
	
test1c.o: gestionFichiers.h gestionFichiers.c test1c.c
	gcc -c test1c.c

2b1: gestionFichiers.o test2b1.o
	gcc gestionFichiers.o test2b1.o -o 2b1

test2b1.o: gestionFichiers.h gestionFichiers.c test2b1.c
	gcc -c test2b1.c

2b2: gestionFichiers.o test2b2.o
	gcc gestionFichiers.o test2b2.o -o 2b2

test2b2.o: gestionFichiers.h gestionFichiers.c test2b2.c
	gcc -c test2b2.c

2b3: gestionFichiers.o test2b3.o
	gcc gestionFichiers.o test2b3.o -o 2b3

test2b3.o: gestionFichiers.h gestionFichiers.c test2b3.c
	gcc -c test2b3.c

2b4: gestionFichiers.o test2b4.o
	gcc gestionFichiers.o test2b4.o -o 2b4

test2b4.o: gestionFichiers.h gestionFichiers.c test2b4.c
	gcc -c test2b4.c
	
2b5: gestionFichiers.o test2b5.o
	gcc gestionFichiers.o test2b5.o -o 2b5

test2b5.o: gestionFichiers.h gestionFichiers.c test2b5.c
	gcc -c test2b5.c

3b1: gestionFichiers.o test3b1.o
	gcc gestionFichiers.o test3b1.o -o 3b1

test3b1.o: gestionFichiers.h gestionFichiers.c test3b1.c
	gcc -c test3b1.c
	
3b2: gestionFichiers.o test3b2.o
	gcc gestionFichiers.o test3b2.o -o 3b2

test3b2.o: gestionFichiers.h gestionFichiers.c test3b2.c
	gcc -c test3b2.c

3b3: gestionFichiers.o test3b3.o
	gcc gestionFichiers.o test3b3.o -o 3b3

test3b3.o: gestionFichiers.h gestionFichiers.c test3b3.c
	gcc -c test3b3.c

gestionFichiers.o: gestionFichiers.c gestionFichiers.h
	gcc -c gestionFichiers.c

clean:
	rm -rf *.o