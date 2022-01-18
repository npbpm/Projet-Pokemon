#pragma once

#include "pokemon.h"
#include "pokemonTypes.h"

typedef struct Ressources {
	int stardust;
	int candies;
}Ressources;

typedef struct Pokedex {
	Pokemon* mesPokemons;
	int capacity;
	int nbPokemons;
}Pokedex;

Pokedex* initPokedex(const int size);

void insertPokemon(Pokedex* monPokedex, Pokemon p);

void displayPokedex(Pokedex* pokedex, EspecePokemon bestiaire[150], const char* typesLabel[], int* point_stardust, int* point_candies);

Pokemon genererPokemon(Pokedex* pokedex, EspecePokemon bestiaire[150], const char* typesLabel[], int* point_stardust, int* point_candies);

