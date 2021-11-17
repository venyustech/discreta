#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    //definindo uma string
    string palavra;

    //Imprimindo na tela
    cout << "Digite uma palavra";

    //Lendo uma string
    cin >> palavra;

    //Imprimindo uma variavel
    cout << "\nA palavra eh:\n" << palavra;

    return EXIT_SUCCESS;
}
