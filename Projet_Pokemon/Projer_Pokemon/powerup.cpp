//Fonction Powerup

#include "pokemon.h"
#include "Pokedex.h"
#include <iostream>
using namespace std;

void powerup(Pokemon* Selection, int* point_stardust, int* point_candies) {
	double boost;
	if (*point_stardust >= 500 && *point_candies >= 10) {
		boost = Selection->CP * 25 / 100;
		Selection->CP += boost;
		*point_stardust = *point_stardust - 500;
		*point_candies = *point_candies - 10;
		cout << "\tVotre Pokemon est devenu beaucoup plus fort!" << endl;
		cout << endl;
	}
	else {
		cout << "\tVous n'avez pas assez de ressources pour effectuer cette operation" << endl;
	}
}
