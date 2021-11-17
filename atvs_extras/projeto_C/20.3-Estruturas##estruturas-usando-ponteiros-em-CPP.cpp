#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <new>

using namespace std;

struct fruta
{
    string cor;
    string nome;
    
};

int main(void)
{
    fruta *primeiraFruta = new fruta;

    primeiraFruta -> cor = "Amarelo";
    primeiraFruta -> nome = "Banana";

    cout << "Fruta: " << primeiraFruta->nome<<", cor: "<< primeiraFruta->cor <<"\n";

    // criando lista de frutas:
    fruta *ListaDeFrutas = new fruta[2];

    ListaDeFrutas[0].cor = "vermelho"; 
    ListaDeFrutas[1].cor =  "verde";
    ListaDeFrutas[0].nome = "morango";
    ListaDeFrutas[1].nome = "kiwi";

    // imprimindo na tela:
    
    for(int i = 0; i < 2; i++)
        cout << "\nFruta: " << ListaDeFrutas[i].nome <<", cor: " << ListaDeFrutas[i].cor << "\n";


    return 0;
}
