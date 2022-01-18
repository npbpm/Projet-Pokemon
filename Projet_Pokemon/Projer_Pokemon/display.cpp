//Prototype de la fonction display

#include "pokemon.h"
#include "pokemonTypes.h"	
#include "bestiaire.h"
#include <iostream>
using namespace std;


void display(const Pokemon& p, EspecePokemon bestiaire[],const char* typesLabel[]) {
	short indice;
	int type;
	indice = recherchePokemon(p, bestiaire);
	type = bestiaire[indice].type;
	
	cout << "\t" << p.nom << "|" << "Type: " << typesLabel[type] << "| (Evolution: " << p.evolution << ")" << endl;
	cout << "\t" << "XP: " << p.XP << "|" << "PV: " << p.PV << "|" << "CP: " << p.CP << endl;
	cout << endl;
}