all: Mochiladp.o
	gcc Mochiladp.o -std=c99 -o Mochiladp -Wall

Mochiladp.o:
	gcc -c Mochiladp.c -o Mochiladp.o

clean:
	rm *.o Mochiladp

run:
	./Mochiladp