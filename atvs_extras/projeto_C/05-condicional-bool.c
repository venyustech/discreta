#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (void)
{
    bool a = true, b = false;

    if(a)
    {
        printf("a eh: %d",a);
    }
    if (!b)/* Comparacao de falsidade: se b == false (mesma coisa)*/
    {
        printf("\nb eh: %d\n\n",b);
    }
    return EXIT_SUCCESS;
}
