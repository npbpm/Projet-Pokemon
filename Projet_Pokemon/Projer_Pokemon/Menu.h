#pragma once
//Déclaration du prototype de la fonction Menu

#include "pokemonTypes.h"
#include "Pokedex.h"
#include "combat.h"

int Menu(EspecePokemon bestiaire[], Pokedex* pokedex, const char* typesLabel[], int* point_stardust, int* point_candies, historique* Historique, CombatHash* combatHash);