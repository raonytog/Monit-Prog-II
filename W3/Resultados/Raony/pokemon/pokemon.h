// pokemon.h

#ifndef POKEMON_H
#define POKEMON_H

typedef struct Pokemon Pokemon;

Pokemon* criaPokemon();
void imprimePokemon(Pokemon* pokemon);
void liberaPokemon(Pokemon* pokemon);

Pokemon** criaListaPokemons(int numPokemons);
void liberaListaPokemons(Pokemon** listaPokemons, int numPokemons);

#endif
