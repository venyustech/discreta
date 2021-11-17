#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main ()
{
    int d=true;

    if(d == true)
    {
        printf("\n d = %d\n digite um valor de novo para d:\n", d);
        scanf("%d",&d);
        printf("\n novo valor de d: \n d = %d", d);
    }
    return EXIT_SUCCESS;
}
