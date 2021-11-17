/*Tabuada de multiplicacao do 5*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int contador; /*normalmente a variavel contador eh "i"*/

    for(contador = 1; contador <= 10; contador++)
    {
        printf("5 X %d = %d\n",contador, 5*contador);
    
    }

    return EXIT_SUCCESS;
}
