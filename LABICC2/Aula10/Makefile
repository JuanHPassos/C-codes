all: main.o arvorebinaria.o hash.o
	gcc arvorebinaria.o hash.o main.o -std=c99 -o main -Wall

main.o:
	gcc -c main.c -o main.o

hash.o:
	gcc -c hash.c -o hash.o

arvorebinaria.o:
	gcc -c arvorebinaria.c -o arvorebinaria.o
clean:
	-rm *.o main
run:
	./main