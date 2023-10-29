#include <stdio.h>
#include "produtos.h"

int main () {
    int acao = 0, tamanho = 6, total = 0;
    Produtos ** listaProdutos = produtos_lista_criar(&tamanho);

    while (acao != 3) {
        acao = produtos_menu_opcoes(); // imprime o menu e o usuario escolhe a acao

        switch (acao) {
            case 1: // cadastra produto
                produtos_lista_cadastrar(listaProdutos, &tamanho, &total);
                break;

            case 2: // exibe lista dos produtos
                produtos_lista_exibir(listaProdutos, &total);
                break;

            case 3:
                produtos_lista_liberar_memoria(listaProdutos, &tamanho);
                produtos_sair(); // encerra o programa
                break;

            default:
                printf("Opcao informada nao existe!\n");
                break;
        }
    }
    return 0;
}