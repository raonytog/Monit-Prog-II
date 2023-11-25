#include "pokemon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pokemon {
    char name[21];
    int lvl;
    float hp, atk, def;
};

Pokemon* criaPokemon() {
    Pokemon * pokemon = malloc(sizeof(Pokemon));
    scanf("%s%*c", pokemon->name);
    scanf("%d%*c%f%*c%f%*c%f%*c", &pokemon->lvl, &pokemon->hp, &pokemon->atk, &pokemon->def);

    return pokemon;
}

void imprimePokemon(Pokemon* pokemon) {
    printf("=======================================================\n");
    printf("POKEMON: %s\n", pokemon->name);
    printf("Nivel: %d\n", pokemon->lvl);
    printf("HP: %.2f\n", pokemon->hp);
    printf("Ataque: %.2f\n", pokemon->atk);
    printf("Defesa: %.2f\n", pokemon->def);
    printf("=======================================================\n");
}

void liberaPokemon(Pokemon* pokemon) {
    free(pokemon);
}

Pokemon** criaListaPokemons(int numPokemons) {
    Pokemon ** p = malloc(numPokemons * sizeof(Pokemon *));
    return p;
}

void liberaListaPokemons(Pokemon** listaPokemons, int numPokemons) {
    for (int i = 0; i < numPokemons; i++) 
        liberaPokemon(listaPokemons[i]);

    free(listaPokemons);
}