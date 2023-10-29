#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>

Produtos* produto_criar() {
    Produtos * produto = (Produtos *) malloc(sizeof(Produtos));
    produto->nome[0] = '\n';
    produto->preco = 0;
    produto->quantidade = 0;

    scanf("%[^\n]%*c", produto->nome);
    scanf("%f%*c", &produto->preco);
    scanf("%d%*c", &produto->quantidade);
    return produto;
}

void produtos_liberar_memoria(Produtos* produto) {
    free(produto);
}

Produtos** produtos_lista_criar(int *tamanho_lista) {
    Produtos** p = malloc(*tamanho_lista * sizeof(Produtos*));
    for(int i = 0; i < *tamanho_lista; i++)
        p[i] = NULL;

    return p;
}

void produtos_lista_cadastrar(Produtos **lista_produtos, int *tamanho_alocado, int *tamanho_lista) {
    if (*tamanho_lista >= *tamanho_alocado) {
        //Se a lista está cheia, realoque mais espaço
        (*tamanho_alocado)++;
        lista_produtos = (Produtos **)realloc(lista_produtos, *tamanho_alocado * sizeof(Produtos*));
        lista_produtos[*tamanho_lista] = NULL;
    }

    lista_produtos[*tamanho_lista] = produto_criar(); 
    (*tamanho_lista)++;
}


void produtos_lista_exibir(Produtos **lista_produtos, int *tamanho_lista) {
    if (lista_produtos == NULL) return;
    int i = 0;

    printf("Lista de produtos cadastrados:\n");
    for (i = 0; i < *tamanho_lista; i++) {
        printf("Produto %d:\n", i+1);
        printf("Nome: %s\n", lista_produtos[i]->nome);
        printf("Preco: %.2f\n", lista_produtos[i]->preco);
        printf("Quantidade em estoque: %d\n", lista_produtos[i]->quantidade);
    }
}

void produtos_lista_liberar_memoria(Produtos** lista_produtos, int *tamanho_lista) {
    int i = 0, total = tamanho_lista;
    for (i = 0; i < total; i++) 
        produtos_liberar_memoria(lista_produtos[i]);

    free(lista_produtos);
}

void produtos_sair() {
    exit(1);
}

int produtos_menu_opcoes() {
    int opcao = 0;
    printf("===== Sistema de Registro de Produtos =====\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Exibir lista de produtos cadastrados\n");
    printf("3 - Sair do programa\n");
    printf("Escolha uma opcao: \n");
    scanf("%d%*c", &opcao);
    return opcao;
}