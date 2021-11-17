#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    //definindo uma matriz
    int matriz [2][2],i,j;

    /*
    passando valores

    matriz [0][0]=1;
    matriz [0][1]=2;
    matriz [1][0]=3;
    matriz [1][1]=4;
    */

    //lendo valores do usuario:

    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
        {
            cout << "escolha o valor para matriz[" << i << "][" << j <<"]:";
            cin >> matriz[i][j];
            cout << "\n";
        }

    //Imprimindo valores na tela 

    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
        {
            //cout << "i = " << i << ", j = " << j << "\n";
            cout << " matriz[" << i << "][" << j << "] = " << matriz[i][j] << "\n";
        }

    return EXIT_SUCCESS;
}
