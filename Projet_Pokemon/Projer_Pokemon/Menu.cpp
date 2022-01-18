//Fonction d'affichage du menu et sisie de la commande

#include "ad_hoc.h"
#include "bestiaire.h"
#include "pokemon.h"
#include "Pokedex.h"
#include <string>
#include <iostream>
#include "combat.h"
using namespace std;


int Menu(EspecePokemon bestiaire[], Pokedex* pokedex, const char* typesLabel[], int* point_stardust, int* point_candies, historique* Historique, CombatHash* combatHash) {
	short nb;
	const char* termine;
	short newChoice;

	do {
		ad_hoc();
		cin >> nb;
		if (nb <= 0 || nb > 7)
			cout << "\tErreur: Numéro invalide, veuillez réessayer" << endl;
	} while (nb <= 0 || nb > 7);	//Cette boucle nous permet d'afficher le menu jusqu'à ce que l'utilisateur rentre une variable valide 

	switch (nb){
	case 1:
		affichageBestiaire(bestiaire);
		break;
	case 2:
		displayPokedex(pokedex, bestiaire, typesLabel, point_stardust, point_candies);
		break;
	case 3:
		genererPokemon(pokedex, bestiaire, typesLabel, point_stardust, point_candies);
		break;
	case 4:
		return nb;
		break;
	case 5:
		displayPokedex(pokedex, bestiaire, typesLabel, point_stardust, point_candies);
		if (pokedex->nbPokemons <= 1) {
			cout << "\tVous n'avez pas assez de pokemons pour faire un combat, essayez d'attraper quelques uns avant!" << endl;
			cout << endl;
			break;
		}else
			combat(pokedex, combatHash, bestiaire);
		break;
	case 6:
		menu_historique(Historique);
		break;
	case 7:
		cout << endl;
		cout << "\tA la prochaine!" << endl;
		cout << endl;
		cout << endl;

		printf("              _.--\"\"`-..\n");
		printf("            ,'          `.\n");
		printf("          ,'          __  `.\n");
		printf("         /|          \" __   \\\n");
		printf("        , |           / |.   .\n");
		printf("        |,'          !_.'|   |\n");
		printf("      ,'             '   |   |\n");
		printf("     /              |`--'|   |\n");
		printf("    |                `---'   |\n");
		printf("     .   ,                   |                       ,\".\n");
		printf("      ._     '           _'  |                    , ' \\ `\n");
		printf("  `.. `.`-...___,...---\"\"    |       __,.        ,`\"   L,|\n");
		printf("  |, `- .`._        _,-,.'   .  __.-'-. /        .   ,    \\\n");
		printf("-:..     `. `-..--_.,.<       `\"      / `.        `-/ |   .\n");
		printf("  `,         \"\"\"\"'     `.              ,'         |   |  ',,\n");
		printf("    `.      '            '            /          '    |'. |/\n");
		printf("      `.   |              \\       _,-'           |       ''\n");
		printf("        `._'               \\   '\"\\                .      |\n");
		printf("           |                '     \\                `._  ,'\n");
		printf("           |                 '     \\                 .'|\n");
		printf("           |                 .      \\                | |\n");
		printf("           |                 |       L              ,' |\n");
		printf("           `                 |       |             /   '\n");
		printf("            \\                |       |           ,'   /\n");
		printf("          ,' \\               |  _.._ ,-..___,..-'    ,'\n");
		printf("         /     .             .      `!             ,j'\n");
		printf("        /       `.          /        .           .'/\n");
		printf("       .          `.       /         |        _.'.'\n");
		printf("        `.          7`'---'          |------\"'_.'\n");
		printf("       _,.`,_     _'                ,''-----\"'\n");
		printf("   _,-_    '       `.     .'      ,\\\n");
		printf("   -\" /`.         _,'     | _  _  _.|\n");
		printf("    \"\"--'---\"\"\"\"\"'        `' '! |! /\n");
		printf("                            `\" \" -' \n");
		printf("\n");
		printf("\n");
		break;
	default:
		return nb;
		break;
	}

	return nb;
}