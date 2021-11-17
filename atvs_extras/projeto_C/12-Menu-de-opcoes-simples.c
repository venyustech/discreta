#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int opcao;

    while(opcao < 1 || opcao >3)/* Se digitou um numero errado repete a pergunta */
    {
        printf("Escolha uma opcao:\n\n");
        printf("1- Opcao 1 :\n");
        printf("2- Opcao 2 :\n");
        printf("3- Opcao 3 :\n\n");
        scanf("%d",&opcao);

        switch(opcao)
        {
            case 1:
                printf("\n Opcao 1 foi escolhida\n");
                break;
            case 2:
                printf("\n Opcao 2 foi escolhida\n");
                break;

            case 3:
                printf("\n Opcao 3 foi escolhida\n");
                break;
            default: 
                printf("\n Opcao invalida\n");
        }
    }
    return EXIT_SUCCESS;
}
