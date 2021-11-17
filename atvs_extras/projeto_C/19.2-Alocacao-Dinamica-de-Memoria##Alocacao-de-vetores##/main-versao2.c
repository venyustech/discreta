#include <stdio.h>
#include <stdlib.h>

void alocaVetor( int tamanho, int *resposta){
    //criado um ponteiro auxiliar

    //alocacao dinamica de memoria:"(int*) casting
    *resposta =(int*)  malloc((tamanho +1 )* sizeof(int));
    
    return;

}

int main (void)
{
    //
    int vetor, tamanho, i;

    //lendo o tamanho do vetor pelo usuario
    printf("Digite o tamanho do vetor\n");
    scanf("%d",&tamanho);

    //ponteiro recebe o endereço de memoria que foi alocado para o vetor

    alocaVetor(tamanho, &vetor);

    for(i = 0; i < tamanho; i++)
    {
        vetor[i] = i;
        printf("vetor[%d] = %d\n", vetor[i], i);
    }

    //limpa memoria:
    free(vetor);

    return EXIT_SUCCESS;
}
