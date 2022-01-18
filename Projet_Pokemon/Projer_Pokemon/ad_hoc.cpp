//Fonction ad_hoc qui affiche le menu

#include <iostream>
#include "pokemon.h"
using namespace std;

void ad_hoc() {
	cout << "\t1. Index des pokemons" << endl;
	cout << "\t2. Mon Pokedex" << endl;
	cout << "\t3. Attraper un pokemon" << endl;
	cout << "\t4. Power-up et evolution" << endl;
	cout << "\t5. Combat" << endl;
	cout << "\t6. Historique evolutions" << endl;
	cout << "\t7. Quitter" << endl;
};

void menu_evolution() {
	cout << "\tTapez 1 pour booster le pouvoir d'un de vos pokemons" << endl;
	cout << "\tTapez 2 pour faire evoluer un de vos pokemons" << endl;
};

void menu_historique(historique* Historique) {
	short i = 0;
	cout << "\tHistorique: " << endl;
	cout << endl;
	Evolution* point = Historique->start;
	for (i; i < Historique->size; i++) {
		cout << "\tEvolution anterieur: " << point->preEvol << "| " << "Evolution actuelle: " << point->postEvol << endl;
		point = point->next;
	};
	cout << endl;
};