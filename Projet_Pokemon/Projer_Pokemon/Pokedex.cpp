#include "Pokedex.h"
#include "pokemon.h"
#include <string>
#include <random>
#include <iostream>
using namespace std;

Pokedex* initPokedex(const int size) {
	Pokedex* pokedex = new Pokedex;
	pokedex->mesPokemons = new Pokemon[size];
	pokedex->capacity = size;
	pokedex->nbPokemons = 0;
	return pokedex;
};



void insertPokemon(Pokedex* monPokedex, Pokemon p) {
	if (monPokedex->nbPokemons == monPokedex->capacity) {
		const int newCapacity = monPokedex->capacity + monPokedex->capacity*0.5;
		Pokemon* bigger_pokemon_tab = new Pokemon[newCapacity];
		memcpy(bigger_pokemon_tab, monPokedex->mesPokemons, sizeof(Pokemon*) * monPokedex->nbPokemons);		
		monPokedex->mesPokemons = bigger_pokemon_tab;
		
	}
	else {
		if (monPokedex->nbPokemons == 0) {
			monPokedex->mesPokemons[0] = p;
		}
		else {
			int i = 0;
			while (i <monPokedex->nbPokemons && strcmp(p.nom, monPokedex->mesPokemons[i].nom) > 0) {
				i++;
			};

			if (i == monPokedex->nbPokemons) {
				monPokedex->mesPokemons[i] = p;
			}
			else {
				for (int k = monPokedex->nbPokemons - 1; k >= i; k--) {
					monPokedex->mesPokemons[k + 1] = monPokedex->mesPokemons[k];
				}
				monPokedex->mesPokemons[i] = p;
			}
		};
	};
	monPokedex->nbPokemons = monPokedex->nbPokemons + 1;
};

void displayPokedex(Pokedex* pokedex, EspecePokemon bestiaire[150], const char* typesLabel[], int* point_stardust, int* point_candies){
	cout << endl;
	cout << endl << "\tContenu du pokedex (Actuellement ";
	cout << pokedex->nbPokemons << " pokemons captures)" << endl;
	for (int i = 0; i < pokedex->nbPokemons; i++) {
		cout << "\tIndice dans la Pokedex:" << i << endl;
		display(pokedex->mesPokemons[i], bestiaire, typesLabel);
	}
	cout << "\t----------------------------------" << endl;
	cout << "\tVos Ressources:" << endl;
	cout << endl;
	cout << "\tBonbons:" << *point_candies << "| Stardust:" << *point_stardust << endl;
	cout << endl;
}

const int MIN_POKEDEX = 0;		//On définit les intervalles pour chacune des valeurs
const int MAX_POKEDEX = 149;
const int MIN_CP = 200;
const int MAX_CP = 1000;
const int MIN_PV = 30;
const int MAX_PV = 500;

random_device rd;		//On a besoin pour choisir un nombre au hassard
mt19937 eng(rd());

uniform_int_distribution<int> distr_pokedex(MIN_POKEDEX, MAX_POKEDEX);
uniform_int_distribution<int> distr_CP(MIN_CP, MAX_CP);
uniform_int_distribution<int> distr_PV(MIN_PV, MAX_PV);
uniform_int_distribution<int> distr_capture(0, 100);


Pokemon genererPokemon(Pokedex* pokedex, EspecePokemon bestiaire[150],const char* typesLabel[], int* point_stardust, int* point_candies) {
	int RandomPokemon;
	short choix;
	short isCaptured;
	do {
		RandomPokemon = distr_pokedex(eng);
	} while (bestiaire[RandomPokemon].estEvolue == true);

	Pokemon nouveauPokemon;
	nouveauPokemon.nom = bestiaire[RandomPokemon].nom;
	nouveauPokemon.XP = 0;
	nouveauPokemon.CP = distr_CP(eng);
	nouveauPokemon.PV = distr_PV(eng);

	cout << endl;
	cout << "\tUn pokemon sauvage est apparue!" << endl;
	cout << "\tVoici ses caractéristiques:" << endl;
	display(nouveauPokemon, bestiaire, typesLabel);
	cout << "\t_________________________________________" << endl;

	cout << "\tQue voulez vous faire?" << endl;
	cout << "\tTapez 1 pour le capturer" << endl;
	cout << "\tTapez 2 pour essayer de capturer un autre" << endl;
	cout << "\tTapez 3 pour revenir au menu principal" << endl;
	cin >> choix;

	switch (choix)
	{
	case 1:
		isCaptured = distr_capture(eng);
		if (isCaptured <= 40) {
			cout << "\tFelicitations! Vous pourrez voir votre nouveau pokemon dans votre pokedex." << endl;
			cout << endl;
			insertPokemon(pokedex, nouveauPokemon);
			*point_candies = *point_candies + 3;
			*point_stardust = *point_stardust + 100;
			return nouveauPokemon;
		}
		else {
			cout << "\tVous n'avez pas réussit à capturer le Pokemon" << endl;
			cout << endl;
		}
		break;
	case 2:
		return genererPokemon(pokedex, bestiaire, typesLabel, point_stardust, point_candies);
		break;
	case 3:
		cout << "\tVous avez decider de partir" << endl;
		cout << endl;
		break;
	default:
		break;
	}
}

void insertHistorique(historique* historique, Evolution* evolution) {
	Evolution* newStart = evolution;
	Evolution* oldStart = historique->start;
	historique->start = newStart;
	evolution->next = oldStart;
}