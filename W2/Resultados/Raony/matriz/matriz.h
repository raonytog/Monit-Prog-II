#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int **matriz; // Valores da matriz
    int qtdColunas; // Quantidade de colunas da matriz
    int qtdLinhas;  // Quantidade de linhas da matriz
} tMatriz;

// Funcao para alocar uma matriz
tMatriz* criaMatriz();

// Funcao que retorna a quantidade de linhas da matriz
int getQtdColunas(tMatriz *matriz);

// Funcao que retorna a quantidade de colunas da matriz
int getQtdLinhas(tMatriz *matriz);

// Funcao que aumenta a quantidade de linhas da matriz, de acordo com o novo valor fornecido
void ajustaQtdLinhasMatriz(tMatriz *matriz, int novaQtdLinhas);

// Funcao que aumenta a quantidade de colunas da matriz, de acordo com o novo valor fornecido
void ajustaQtdColunasMatriz(tMatriz *matriz, int novaQtdColunas);

/*
 * Funcao para processar a entrada de dados na matrix
 * pos_x representa a coluna em que o valor deve ser colocado
 * pos_y representa a linha em que o valor deve ser colocado
 * valor representa o valor a ser adicionado na matriz
*/
void processaValorMatriz(tMatriz *matriz, int pos_x, int pos_y, int valor);

// Funcao que imprime a matriz
void printMatriz(tMatriz *matriz);

// Funcao para liberar a memoria alocada para uma matriz
void destroiMatriz(tMatriz *matriz);