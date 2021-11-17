#include <stdio.h>
#include <stdlib.h>

int* alocaVetor( int tamanho){
    //criado um ponteiro auxiliar
    int *aux;

    //alocacao dinamica de memoria:"(int*) casting
    aux =(int*)  malloc(tamanho * sizeof(int));
    
    return aux;

}

int main (void)
{
    //
    int *vetor, tamanho, i;

    //lendo o tamanho do vetor pelo usuario
    printf("Digite o tamanho do vetor\n");
    scanf("%d",&tamanho);

    //ponteiro recebe o endereço de memoria que foi alocado para o vetor

    vetor = alocaVetor(tamanho);

    for(i = 0; i < tamanho; i++)
    {
        vetor[i] = i;
        printf("vetor[%d] = %d\n", vetor[i], i);
    }

    //limpa memoria:
    free(vetor);

    return EXIT_SUCCESS;
}
