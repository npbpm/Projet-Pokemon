/*Projet Pokemon
Date: 27/10/21
Auteur: Nicolas Pérez*/

#include "Menu.h"
#include "pokemonTypes.h"
#include "pokemon.h"
#include "bestiaire.h"
#include "Pokedex.h"
#include <iostream>
#include "ad_hoc.h"
#include "combat.h"
using namespace std;


int main() {
	short resMenu = 0, newChoice;

	EspecePokemon bestiaire[150];
	initBestiaire(bestiaire);

	Pokedex* pokedex = initPokedex(10);

	historique* Historique = new historique;
	Historique->start = nullptr;

	Ressources Ressources;
	Ressources.candies = 500;
	Ressources.stardust = 1000;
	int* point_stardust = &Ressources.stardust;
	int* point_candies = &Ressources.candies;

	const char* typesLabel[18] = { "Normal", "Fighting", "Flying", "Poison", "Ground", "Rock", "Bug",
		"Ghost", "Steel", "Fire", "Grass", "Water", "Electric", "Psychic",
		"Ice", "Dragon", "Dark", "Fairy" };

	CombatHash* combatHash = initCombatHash();

	cout << "\tBienvenue sur le jeux pokemon TSE version FISE1 (2021 - 22)!" << endl;
	cout << "\tAuteur: Nicolas Perez" << endl;
	cout << endl;
	cout << endl;

	printf("                 .\"-,.__\n");
	printf("                 `.     `.  ,\n");
	printf("              .--'  .._,'\"-' `.\n");
	printf("             .    .'         `'\n");
	printf("             `.   /          ,'\n");
	printf("               `  '--.   ,-\"'\n");
	printf("                `\"`   |  \\\n");
	printf("                   -. \\, |\n");
	printf("                    `--Y.'      ___.\n");
	printf("                         \\     L._, \\\n");
	printf("               _.,        `.   <  <\\                _\n");
	printf("             ,' '           `, `.   | \\            ( `\n");
	printf("          ../, `.            `  |    .\\`.           \\ \\_\n");
	printf("         ,' ,..  .           _.,'    ||\\l            )  '\".\n");
	printf("        , ,'   \\           ,'.-.`-._,'  |           .  _._`.\n");
	printf("      ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\\n");
	printf("    .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`.\n");
	printf("    |  '          ..         `-...-\"  |  `-'      / /        . `.\n");
	printf("    | /           |L__           |    |          / /          `. `.\n");
	printf("   , /            .   .          |    |         / /             ` `\n");
	printf("  / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \\\n");
	printf(" / .           \\\"`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`.\n");
	printf(".  '         .-f    ,'   `    '.       \\__.---'     _   .'   '     \\ \\\n");
	printf("' /          `.'    l     .' /          \\..      ,_|/   `.  ,'`     L`\n");
	printf("|'      _.-\"\"` `.    \\ _,'  `            \\ `.___`.'\"`-.  , |   |    | \\\n");
	printf("||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|\n");
	printf("||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||\n");
	printf("|| '              V      / /           `   | `   ,'   ,' '.    !  `. ||\n");
	printf("||/            _,-------7 '              . |  `-'    l         /    `||\n");
	printf(". |          ,' .-   ,' ||               | .-.        `.      .'     ||\n");
	printf(" `'        ,'    `\".'    |               |    `.        '. -.'       `'\n");
	printf("          /      ,'      |               |,'    \\-.._,.'/'\n");
	printf("          .     /        .               .       \\    .''\n");
	printf("        .`.    |         `.             /         :_,'.'\n");
	printf("          \\ `...\\   _     ,'-.        .'         /_.-'\n");
	printf("           `-.__ `,  `'   .  _.>----''.  _  __  /\n");
	printf("                .'        /\"'          |  \"'   '_\n");
	printf("               /_|.-'\\ ,\".             '.'`__'-( \\\n");
	printf("                 / ,\"'\"\\,'               `/  `-.|\" \n");
	cout << endl;
	cout << endl;



	do {
		resMenu = Menu(bestiaire, pokedex, typesLabel, point_stardust, point_candies, Historique, combatHash);

		if (resMenu == 4 && pokedex->nbPokemons != 0) {
			menu_evolution();
			cin >> newChoice;	
			if (newChoice == 1) {
				cout << "\tQuel pokemon voulez vous booster (indice)?" << endl;
				int choice;
				displayPokedex(pokedex, bestiaire, typesLabel, point_stardust, point_candies);
				cin >> choice;
				Pokemon* Selection = &pokedex->mesPokemons[choice];
				powerup(Selection, point_stardust, point_candies);
			}
			else {
				cout << "\tQuel pokemon voulez vous evoluer?" << endl;
				int choice;
				displayPokedex(pokedex, bestiaire, typesLabel, point_stardust, point_candies);
				cin >> choice;
				Pokemon* Selection = &pokedex->mesPokemons[choice];
				evolve(Selection, bestiaire, point_stardust, point_candies, Historique);
			}
		}
		else {
			if (pokedex->nbPokemons == 0 && resMenu == 4) {
				cout << "\tVous n'avez pas de pokemons actuellement." << endl;
				cout << endl;
			}
		}
	} while (resMenu < 7);

return 0;
}




