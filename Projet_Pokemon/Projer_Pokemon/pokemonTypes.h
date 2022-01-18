#pragma once
// le type enuméré décrivant le type de Pokemon parmi les 18 existants
typedef enum {
	Normal, Fighting, Flying, Poison, Ground, Rock, Bug,
	Ghost, Steel, Fire, Grass, Water, Electric, Psychic,
	Ice, Dragon, Dark, Fairy
}PokemonType;

//Déclaration de la structure EspecePokemon

typedef struct EspecePokemon {
	char* nom;
	bool estEvolue;
	const char* evolvesTo;
	PokemonType type;
	int nbBonbonsPourEvoluer;
}EspecePokemon;