#include <stdio.h>
#include <string.h>
#include "pokemon.h"

int main() {
    int qtdPokemons = 0;
    scanf("%d%*c", &qtdPokemons);
    Pokemon ** pokemons = criaListaPokemons(qtdPokemons);
    for (int i = 0; i < qtdPokemons; i++)
        pokemons[i] = criaPokemon();

    for (int i = 0; i < qtdPokemons; i++) 
        imprimePokemon(pokemons[i]);

    liberaListaPokemons(pokemons, qtdPokemons);
    return 0;
}