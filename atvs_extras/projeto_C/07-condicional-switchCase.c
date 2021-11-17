#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a;
    char b;

    printf("\n Opcao escolhida de 0 a 3:\n ");
    scanf("%d",&a);
    printf("\n Opcao escolhida de char: ");
    scanf(" %c",&b);/*(tem q colocar espaco se nao nao le)*/
    switch(a)
    {
        case 1:
            printf("\n Opcao escolhida: 1");
            break;
        case 2:
            printf("\n Opcao escolhida: 2");
            break;
        case 3:
            printf("\n Opcao escolhida: 3");
            break;
        default:
            printf("\n Opcao invalida\n");
            break;
    }
    switch(b)
    {
        case 'b':
            printf("\n Opcao escolhida do char: b\n");
            break;
        case 120:
            printf("\n Opcao escolhida do char: x\n");
            break;
        default:
            printf("\n Opcao foi %d\n",b);
            break;
    }
    return EXIT_SUCCESS;
}
