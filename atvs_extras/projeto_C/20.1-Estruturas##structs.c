#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 3

struct palavra
{
    int ordem;
    char letra;
    char texto[255];
    
};

int main(void)
{
    struct palavra primeiraPalavra;
    
    primeiraPalavra.ordem = 10;
    primeiraPalavra.letra = 'c';
    strcpy(primeiraPalavra.texto,"palavrinha");
    
    printf("Ordem: %d , Primeira Letra: %c, palavra: %s", primeiraPalavra.ordem, primeiraPalavra.letra, primeiraPalavra.texto);

    struct palavra listaDePalavras[MAX];

    for(int i = 0; i < MAX; i++)
    {
        listaDePalavras[i].ordem = i;
        listaDePalavras[i].letra = (61+i);
        strcpy(listaDePalavras[i].texto,"palavrinha+i\n"); 
    }

    for(int i = 0; i < MAX; i++)
    {
        printf("\nOrdem: %d , Primeira Letra: %c, palavra: %s", listaDePalavras[i].ordem, listaDePalavras[i].letra, listaDePalavras[i].texto);
    }

    return 0;
}
