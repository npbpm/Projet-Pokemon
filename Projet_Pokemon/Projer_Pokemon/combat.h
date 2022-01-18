#pragma once

#include "pokemonTypes.h"
#include "pokemon.h"
#include "pokedex.h"

typedef struct CombatEspece {
	PokemonType nature;
	char* strongAgainst[5];
	char* weakAgainst[5];
	CombatEspece* next;
} CombatEspece;

typedef struct CombatHash {
	int size = 18;
	CombatEspece* content[26];
} CombatHash;

int Hash(const char* str, CombatHash* hachage);

char* pokemonTypeToString(PokemonType t);

CombatEspece* get(CombatHash* hashtable, char* key);	//Fonction pas encore implémentée car on n'as pas encore vue le cours, à faire la séance 6

bool contains(CombatHash* hashtable, CombatEspece* c);

void insert(CombatEspece* c, CombatHash* hashtable);	//Fonction pas encore implémentée car on n'as pas encore vue le cours, à faire la séance 6

void combat(Pokedex* pokedex, CombatHash* combatHash, EspecePokemon bestiaire[]);

CombatHash* initCombatHash();

PokemonType StringToPokemonType(char* t);