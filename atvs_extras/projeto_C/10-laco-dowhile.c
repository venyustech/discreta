#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
    int a=1, b=1;
    int parada1=false,parada2=false;

    while(a <= 10)/* Compara e depois executa*/
    {   
        if(!parada1)
        {
            printf("Contagem com  While\n");
            parada1=true;
        }
        printf("%d\n",a);
        a++;
    }
    do /*Exacuta e depois compara*/
    {
        if(!parada2)
        {
            printf("\nContagem com  DO WHILE\n");
            parada2=true;
        }
        printf("%d\n",b);
        b++;
    }while(b <= 10);
    return EXIT_SUCCESS;
}
