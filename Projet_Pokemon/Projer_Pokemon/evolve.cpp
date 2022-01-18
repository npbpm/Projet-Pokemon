//Fonction evolve

#include "pokemon.h"
#include "Pokedex.h"
#include "bestiaire.h"
#include "pokemonTypes.h"
#include <iostream>
using namespace std;

void evolve(Pokemon* Selection, EspecePokemon bestiaire[], int* point_stardust, int* point_candies, historique* Historique){
	short indice;
	Evolution* evolution = new Evolution;
	indice = recherchePokemon(*Selection, bestiaire);
	if(*point_candies >= bestiaire[indice].nbBonbonsPourEvoluer){
		if (bestiaire[indice].evolvesTo != nullptr) {
			evolution->preEvol = bestiaire[indice].nom;
			evolution->postEvol = bestiaire[indice + 1].nom;
			insertHistorique(Historique, evolution);
			Historique->size += 1;
			Selection->nom = bestiaire[indice + 1].nom;
			Selection->evolution += 1;
			*point_candies = *point_candies - bestiaire[indice].nbBonbonsPourEvoluer;
			cout << "\tBravo! Votre pokemon a evolue!"<<endl;
			cout << endl;
		}
		else {
			cout << "\tCe pokemon n'as pas d'evolution!" << endl;
			cout << endl;
		}
	}
	else {
		cout << "\tVous n'avez pas assez de ressources pour effectuer cette operation" << endl;
	}
	
}