# Infra_Software_5




## Exercício
Escreva um programa com múltiplos threads que calcule a soma dos itens de uma matriz e adicione exiba o resultado na saída padrão. As matrizes permitidas na entrada terão uma ordem quadrada, ou seja o número de linhas é igual ao número de colunas. O programa precisa necessariamente ser implementado de tal forma que para cada linha da matriz exista uma thread responsável por acessar cada valor da matriz e adicionar o valor acessado a uma variável comum que vai armazenar a soma de todos os itens da matriz.. O programa precisa garantir que cada acesso a essa variável seja feito sem que nenhuma outra thread esteja alterando o valor dessa variável ao mesmo tempo, garantindo a consistência da do resultado no final do programa. O programa não pode ser implementado sem a utilização de threads onde o cálculo seja todo feito na thread principal. A thread principal será responsável por receber os dados e depois de todos os cálculos precisa exibir o resultado. O primeiro parâmetro recebido vai ser a ordem da matriz, os próximos parâmetros serão todos os elementos da matriz. Depois de feito todos os cálculos o programa precisa exibir a soma dos itens.


## Como usar
** Pré-Requisitos
  * editor de codigo
  * C (linguagem)
  * SO Linux
  * makefile

Compilando no terminal (sem usar o makefile) 

```bash

1. gcc "nome do arq".c -o "nome do executavel"

```
```bash

2. ./"nome do executavel"

```

Compilando no terminal (com o makefile)

```bash

1. make 
   - executa o - gcc "nome do arq".c -o "nome do executavel"

```
```bash

2. make run
   - executa o - ./"nome do executavel"

```
```bash

3. make clean
   - executa o -  rm 'nome do executável'
