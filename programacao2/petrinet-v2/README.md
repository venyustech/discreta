# Exercício - petri

## Simulador de Rede de Petri

### Formato do arquivo de entrada:

```
Quantos lugares? (n>0)
Quantas transições? (m)
Quantos arcos consumidores do tipo LT? (l)
Quantos arcos produtores do tipo TL? (t)
Digite quantos tokens em cada lugar, separados por espaco:
Digite a trinca ALT0 de arco consumidor LT no formato L T R:
...
Digite a trinca ALTl de arco consumidor LT no formato L T R:
Digite a trinca ATL0 de arco produtor TL no formato T L R:
...
Digite a trinca ATLt de arco produtor TL no formato T L R:
...
```

Comando para execução:

```
$./ex11.x < petrinet1.txt
```

e também

```
$./ex11.x -f petrinet1.txt
```

Ficando à escolha do usuário decidir que modo prefere chamar o programa.

Nota: caso o usuário não coloque a chave `-f`, deve-se imprimir as questões mostradas acima (modo iterativo, leitura do teclado). Já no caso de se usar a chave `-f`, as questões não devem ser impressas.

### Processamento

* Transições devem rodar em pseudo-paralelismo, ao acaso.
* Transições devem considerar as condições 
    1. pode? - de acordo com as regras estabelecidas em sala
    2. quer? - com `55%` de preferência para o `sim`

### Saída

* A ser discutida em sala, deve incluir estatísticas para indicar o funcionamento da rede de petri. Exemplos:
    - Quantidade de iterações
    - Velocidades:
        - iterações por segundo
        - transições analisadas por segundo
    - Tokens em lugares:
        - Máximos e mínimos
        - Médias e desvios padrões
        - Lugares inalcançáveis ou com overflow (máximo em define para fácil alteração)
* Outros itens se elaborados em sala       

## Sistema no github

* Trabalho em dupla
* O trabalho deverá ter alocação de memória dinâmica com listas, i.e., não deverá ser usados vetores a não ser para tipos de dados com tamanho conhecido de antemão e limitado.
* A avaliação consistirá na participação em:
    - Código contribuído
    - Pull requests (PR) aceitos
    - Atividade nos issues com participação em discussões
    - Identificação (issues) e correção (commits) de bugs
    - Outras atividades no github (milestones, wiki, etc.)
* Uso correto do git no hydra, com ramos para cada tarefa. Ramos na ordem:
    - features
    - develop
    - master (origin)

## Dúvidas

Detalhes não cobertos aqui serão discutidos em sala e adicionados posteriormente, no README se necessário, ou principalmente nos issues (na maioria dos casos, as resoluções estarão por lá).

## Orientação

* Prof. Ruben Carlo Benante
* Contado: rcb@upe.br

