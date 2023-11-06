#include "matriz.h"
#include <stdio.h>

int main(void) {
    int qtdValores = 0;
    int pos_x, pos_y, valor;
    tMatriz *matriz = criaMatriz();

    scanf("%d", &qtdValores);

    for (int i = 0; i < qtdValores; i++) {
        scanf("%d %d %d", &pos_x, &pos_y, &valor);

        processaValorMatriz(matriz, pos_x, pos_y, valor);
    }

    printMatriz(matriz);

    destroiMatriz(matriz);
    
    return 0;
}