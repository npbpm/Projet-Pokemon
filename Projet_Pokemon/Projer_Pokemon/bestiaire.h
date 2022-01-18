#pragma once

#include "pokemonTypes.h"
#include "pokemon.h"

//Déclaration de la procédure initBestiaire

void initBestiaire(EspecePokemon bestiaire[]);

void affichageBestiaire(EspecePokemon bestiaire[]);

void tri(EspecePokemon bestiaire[]);

int recherchePokemon(const Pokemon& p, EspecePokemon bestiaire[]);