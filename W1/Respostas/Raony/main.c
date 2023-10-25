#include <stdio.h>
#include "produtos.h"

int main () {
    int acao = 0, i = 0;
    int * tamanho = 0;
    Produtos ** listaProdutos;

    while (acao != 3) {
        produtos_menu_opcoes(); // imprime o menu
        scanf("%d", &acao);
        scanf("%*c");
        switch (acao) {
            case 1: // cadastra produto
                listaProdutos[i] = produto_criar();
                i++;
                break;

            case 2: // exibe lista dos produtos
                produtos_lista_exibir(* listaProdutos, tamanho);
                break;

            case 3:
                produtos_lista_liberar_memoria(* listaProdutos, tamanho);
                produtos_sair(); // encerra o programa
                break;
            

        }
    }
    return 0;
}