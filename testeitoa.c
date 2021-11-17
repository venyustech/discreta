#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR_FILE 89
#define DEFAULT_VALUE 9

int main()
{
    char numbers[DEFAULT_VALUE][DEFAULT_VALUE];
    char count_c[1];
    int i,j, count = 1;

    itoa(count,count_c,10);
    for(int i = 0; i < DEFAULT_VALUE; i++)
    {
        for(int j = 0; j < DEFAULT_VALUE; j++)
        {
            numbers[i][j] = '0';
        }
    }
    numbers[0][0] = count_c[0];
    for(int i = 0; i < DEFAULT_VALUE; i++)
    {
        for(int j = 0; j < DEFAULT_VALUE; j++)
        {
            // printf ("matriz[%d][%d] = %c\n", i, j, numbers[i][j]);
            printf("%c", numbers[i][j]);
        }
        printf("\n");
    }

   return 0;
}
