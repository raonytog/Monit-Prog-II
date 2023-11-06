#include "matriz.h"

tMatriz* criaMatriz() {
    tMatriz * matriz = (tMatriz *) malloc (sizeof(tMatriz));

    matriz->qtdLinhas = 0;
    matriz->qtdColunas = 0;
    matriz->matriz = NULL;

    return matriz;
}

int getQtdColunas(tMatriz *matriz) {
    return matriz->qtdColunas;
}

int getQtdLinhas(tMatriz *matriz) {
    return matriz->qtdLinhas;
}

// Funcao que aumenta a quantidade de linhas da matriz, de acordo com o novo valor fornecido
void ajustaQtdLinhasMatriz(tMatriz *matriz, int novaQtdLinhas) {
    int antiga = matriz->qtdLinhas;

    // aloca a nova qtd de linhas
    matriz->qtdLinhas = novaQtdLinhas + 1;
    matriz->matriz = realloc (matriz->matriz, getQtdLinhas(matriz) * sizeof(int *));

    // preenche as novas linhas e colunas com 0
    for (int i = antiga; i < getQtdLinhas(matriz); i++) {
        matriz->matriz[i] = malloc (getQtdColunas(matriz) * sizeof(int));

        // preenche as novas linhas com 0
        for (int j = 0; j < getQtdColunas(matriz); j++) {
            matriz->matriz[i][j] = 0;
        }
    }
}

// Funcao que aumenta a quantidade de colunas da matriz, de acordo com o novo valor fornecido
void ajustaQtdColunasMatriz(tMatriz *matriz, int novaQtdColunas) {
    int antiga = matriz->qtdColunas;

    // realoca a qtd de colunas por linha
    matriz->qtdColunas = novaQtdColunas + 1;
    for (int i = 0; i < getQtdLinhas(matriz); i++) {
        matriz->matriz[i] = realloc (matriz->matriz[i], getQtdColunas(matriz) * sizeof(int));

        //preenche as novas colunas com 0
        for (int j = antiga; j < getQtdColunas(matriz); j++) {
            matriz->matriz[i][j] = 0;
        }
    }


}

void processaValorMatriz(tMatriz *matriz, int pos_x, int pos_y, int valor) {
    if (pos_x >= getQtdColunas(matriz)) ajustaQtdColunasMatriz(matriz, pos_x);
    if (pos_y >= getQtdLinhas(matriz)) ajustaQtdLinhasMatriz(matriz, pos_y);
    matriz->matriz[pos_y][pos_x] = valor;
}

void printMatriz(tMatriz *matriz) {
    for (int i = 0; i < getQtdLinhas(matriz); i++) {
        for (int j = 0; j < getQtdColunas(matriz); j++) {
            printf("%d ", matriz->matriz[i][j]);
        }
        printf("\n");
    }
}

void destroiMatriz(tMatriz *matriz) {
    for (int i = 0; i < getQtdLinhas(matriz); i++)
        free(matriz->matriz[i]);
    free(matriz->matriz);

    free(matriz);
}