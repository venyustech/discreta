#include <stdio.h>
#include <stdlib.h>
#include <new>

int main (void)
{
    //
    int *vetor, tamanho, i;

    //lendo o tamanho do vetor pelo usuario
    printf("Digite o tamanho do vetor\n");
    scanf("%d",&tamanho);

    //ponteiro recebe o endereço de memoria que foi alocado para o vetor
    vetor = new int(tamanho);

    for(i = 0; i < tamanho; i++)
    {
        vetor[i] = i;
        printf("vetor[%d] = %d\n", vetor[i], i);
    }
    free(vetor);
    return EXIT_SUCCESS;
}
