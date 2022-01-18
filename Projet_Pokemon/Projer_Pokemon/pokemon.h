#pragma once

#include "pokemonTypes.h"

//Les caractéristiques de chaque Pokemon individuellement
typedef struct Pokemon {
	char* nom;
	int XP, PV, CP;
	short evolution = 1;
}Pokemon;

//Prototype de la fonction Powerup

void powerup(Pokemon* Selection, int* point_stardust, int* point_candies);

//void evolve(Pokemon& p);

//Protoype de la fonction display

void display(const Pokemon& p, EspecePokemon bestiaire[], const char* typesLabel[]);

typedef struct Evolution {
	char* preEvol;
	char* postEvol;
	Evolution* next = nullptr;
} Evolution;

typedef struct {
	int size = 0;
	Evolution* start;
} historique;


//Protoype de la fonction evolve
void evolve(Pokemon* Selection, EspecePokemon bestiaire[], int* point_stardust, int* point_candies, historique* historique);

void insertHistorique(historique* historique, Evolution* evolution);
