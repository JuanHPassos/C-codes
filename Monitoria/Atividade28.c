#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nomeArquivo[10];
    scanf("%s", nomeArquivo);
    FILE *fp = fopen(nomeArquivo, "r");
    
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        free(nomeArquivo);
        return 1;
    }
    
    char byte;
    int contador = 0;
    while (fread(&byte, sizeof(char), 1, fp) == 1)
    {
        contador++;
    }
    
    fclose(fp);
    printf("%d\n", contador);
    return 0;
}