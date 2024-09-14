all: selecao.o Pilha.o item.o
	gcc item.o Pilha.o selecao.o -std=c99 -o selecao -Wall

selecao.o:
	gcc -c selecao.c -o selecao.o

Pilha.o:
	gcc -c Pilha.c -o Pilha.o

item.o:
	gcc -c item.c -o item.o
clean:
	rm *.o selecao
run:
	./selecao