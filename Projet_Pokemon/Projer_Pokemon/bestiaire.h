#pragma once

#include "pokemonTypes.h"
#include "pokemon.h"

//D�claration de la proc�dure initBestiaire

void initBestiaire(EspecePokemon bestiaire[]);

void affichageBestiaire(EspecePokemon bestiaire[]);

void tri(EspecePokemon bestiaire[]);

int recherchePokemon(const Pokemon& p, EspecePokemon bestiaire[]);