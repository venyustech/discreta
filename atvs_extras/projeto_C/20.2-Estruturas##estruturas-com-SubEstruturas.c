#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Data{
    int dia;
    int mes;
    int ano;
}data;

struct aluno
{
    long long int id;
    data nascimento;
    
};

int main(void)
{
    struct aluno Aluno1;

    Aluno1.id = 15;
    Aluno1.nascimento.dia  = 15;
    Aluno1.nascimento.mes  = 5;
    Aluno1.nascimento.ano  = 1997;
    
    printf("Nascido em %d / 0%d / %d.\n", Aluno1.nascimento.dia, Aluno1.nascimento.mes, Aluno1.nascimento.ano);

    return 0;
}
