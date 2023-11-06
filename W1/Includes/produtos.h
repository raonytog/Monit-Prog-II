#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produtos;

Produtos* produto_criar();
void produtos_liberar_memoria(Produtos* produto);

Produtos** produtos_lista_criar(int *tamanho_alocado);
void produtos_lista_cadastrar(Produtos **lista_produtos, int *tamanho_alocado, int *tamanho_lista);
void produtos_lista_exibir(Produtos **lista_produtos, int *tamanho_lista);
void produtos_lista_liberar_memoria(Produtos** lista_produtos, int *tamanho_alocado);

void produtos_sair();
int produtos_menu_opcoes();

#endif