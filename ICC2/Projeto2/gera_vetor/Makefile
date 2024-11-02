all: main.o gera_vetor.o
	gcc main.o gera_vetor.o -o main

gera_vetor.o:
	gcc -c gera_vetor.c -o gera_vetor.o

main.o:
	gcc -c main.c -o main.o

clean:
	rm *.o main

run: main
	./main