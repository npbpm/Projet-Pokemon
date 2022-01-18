#include "combat.h"
#include "pokemonTypes.h"
#include <iostream>
#include "bestiaire.h"
#include <random>
#include <string>
using namespace std;

int Hash(const char* str, CombatHash* hachage) {
	unsigned long hash = 5381;
	int c;
	int size = hachage->size;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c;

	return hash % size;	//On renvoit une valeur modulo size de la table de hachage
};

void insert(CombatEspece* c, CombatHash* hashtable) {
	int p;
	const char* type;
	type = pokemonTypeToString(c->nature);
	p = Hash(type, hashtable);

	if (hashtable->content[p] == nullptr) {
		hashtable->content[p] = c;
	}
	else {
		hashtable->content[p]->next = c;
		c->next = nullptr;
	}
}

CombatEspece* get(CombatHash* hashtable, char* key) {
	int p = Hash(key, hashtable);
	const char* type;
	type = pokemonTypeToString(hashtable->content[p]->nature);

	if (strcmp(type, key) == 0) {
		return hashtable->content[p];
	}
	else {
		do {
			p++;
			do {
				if (hashtable->content[p] == nullptr)
					p++;
			} while (hashtable->content[p] == nullptr);
			if(hashtable->content[p] != nullptr && hashtable->content[p]->next == nullptr)
				type = pokemonTypeToString(hashtable->content[p]->nature);
			else
				do {
					type = pokemonTypeToString(hashtable->content[p]->next->nature);
				} while (strcmp(type, key) != 0);
		} while (strcmp(type, key) != 0);
		return hashtable->content[p];
	}

}

char* pokemonTypeToString(PokemonType t) {
	if (t == Normal) {
		return "Normal";
	}
	else if (t == Fighting) {
		return "Fighting";
	}
	else if (t == Flying) {
		return "Flying";
	}
	else if (t == Poison) {
		return "Poison";
	}
	else if (t == Ground) {
		return "Ground";
	}
	else if (t == Rock) {
		return "Rock";
	}
	else if (t == Bug) {
		return "Bug";
	}
	else if (t == Ghost) {
		return "Ghost";
	}
	else if (t == Steel) {
		return "Steel";
	}
	else if (t == Fire) {
		return "Fire";
	}
	else if (t == Grass) {
		return "Grass";
	}
	else if (t == Water) {
		return "Water";
	}
	else if (t == Electric) {
		return "Electric";
	}
	else if (t == Psychic) {
		return "Psychic";
	}
	else if (t == Ice) {
		return "Ice";
	}
	else if (t == Dragon) {
		return "Dragon";
	}
	else if (t == Dark) {
		return "Dark";
	}
	else {
		return "Fairy";
	}
};

PokemonType StringToPokemonType(char* t) {
	if (t == "Normal") {
		return Normal;
	}
	else if (t == "Fighting") {
		return Fighting;
	}
	else if (t == "Flying") {
		return Flying;
	}
	else if (t == "Poison") {
		return Poison;
	}
	else if (t == "Ground") {
		return Ground;
	}
	else if (t == "Rock") {
		return Rock;
	}
	else if (t == "Bug") {
		return Bug;
	}
	else if (t == "Ghost") {
		return Ghost;
	}
	else if (t == "Steel") {
		return Steel;
	}
	else if (t == "Fire") {
		return Fire;
	}
	else if (t == "Grass") {
		return Grass;
	}
	else if (t == "Water") {
		return Water;
	}
	else if (t == "Electric") {
		return Electric;
	}
	else if (t == "Psychic") {
		return Psychic;
	}
	else if (t == "Ice") {
		return Ice;
	}
	else if (t == "Dragon") {
		return Dragon;
	}
	else if (t == "Dark") {
		return Dark;
	}
	else {
		return Fairy;
	}
};

bool contains(CombatHash* hashtable, CombatEspece* c) {
	char* nature;
	nature = pokemonTypeToString(c->nature);
	CombatEspece* element = get(hashtable, nature);
	return (element != nullptr);
};

CombatHash* initCombatHash()	
{
	CombatHash* hashtable = new CombatHash;
	hashtable->size = 18;
	// Initialisation
	for (int k = 0; k < 26; k++)
	{
		hashtable->content[k] = nullptr;
	}

	// Insertions successives
	int i = -1;
	CombatEspece* bug = new CombatEspece;
	bug->nature = StringToPokemonType("Bug");
	bug->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		bug->strongAgainst[i] = "";
		bug->weakAgainst[i] = "";
	}
	bug->strongAgainst[0] = (char*)"Dark";
	bug->strongAgainst[1] = (char*)"Grass";
	bug->strongAgainst[2] = (char*) "Psychic";
	bug->weakAgainst[0] = (char*) "Fire";
	bug->weakAgainst[1] = (char*) "Flying";
	bug->weakAgainst[2] = (char*) "Rock";
	insert(bug, hashtable);

	CombatEspece* dark = new CombatEspece;
	dark->nature = StringToPokemonType("Dark");
	dark->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		dark->strongAgainst[i] = "";
		dark->weakAgainst[i] = "";
	}
	dark->strongAgainst[0] = (char*)"Ghost";
	dark->strongAgainst[1] = (char*)"Psychic";
	dark->weakAgainst[0] = (char*)"Bug";
	dark->weakAgainst[1] = (char*)"Fairy";
	dark->weakAgainst[2] = (char*)"Fight";
	insert(dark, hashtable);

	CombatEspece* dragon = new CombatEspece;
	dragon->nature = StringToPokemonType("Dragon");
	dragon->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		dragon->strongAgainst[i] = "";
		dragon->weakAgainst[i] = "";
	}
	dragon->strongAgainst[0] = (char*)"Dragon";
	dragon->weakAgainst[0] = (char*)"Dragon";
	dragon->weakAgainst[1] = (char*)"Fairy";
	dragon->weakAgainst[2] = (char*)"Ice";
	insert(dragon, hashtable);

	CombatEspece* electric = new CombatEspece;
	electric->nature = StringToPokemonType("Electric");
	electric->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		electric->strongAgainst[i] = "";
		electric->weakAgainst[i] = "";
	}
	electric->strongAgainst[0] = (char*)"Flying";
	electric->strongAgainst[1] = (char*)"Water";
	electric->weakAgainst[0] = (char*)"Ground";
	insert(electric, hashtable);

	CombatEspece* fairy = new CombatEspece;
	fairy->nature = StringToPokemonType("Fairy");
	fairy->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		fairy->strongAgainst[i] = "";
		fairy->weakAgainst[i] = "";
	}
	fairy->strongAgainst[0] = (char*)"Dark";
	fairy->strongAgainst[1] = (char*)"Dragon";
	fairy->strongAgainst[2] = (char*)"Fight";
	fairy->weakAgainst[0] = (char*)"Poison";
	fairy->weakAgainst[1] = (char*)"Steel";
	insert(fairy, hashtable);

	CombatEspece* fighting = new CombatEspece;
	fighting->nature = StringToPokemonType("Fighting");
	fighting->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		fighting->strongAgainst[i] = "";
		fighting->weakAgainst[i] = "";
	}
	fighting->strongAgainst[0] = (char*)"Dark";
	fighting->strongAgainst[1] = (char*)"Ice";
	fighting->strongAgainst[2] = (char*)"Normal";
	fighting->strongAgainst[3] = (char*)"Rock";
	fighting->strongAgainst[4] = (char*)"Steel";
	fighting->weakAgainst[0] = (char*)"Fairly";
	fighting->weakAgainst[1] = (char*)"Flying";
	fighting->weakAgainst[2] = (char*)"Psychic";
	insert(fighting, hashtable);

	CombatEspece* fire = new CombatEspece;
	fire->nature = StringToPokemonType("Fire");
	fire->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		fire->strongAgainst[i] = "";
		fire->weakAgainst[i] = "";
	}
	fire->strongAgainst[0] = (char*)"Bug";
	fire->strongAgainst[1] = (char*)"Grass";
	fire->strongAgainst[2] = (char*)"Ice";
	fire->strongAgainst[3] = (char*)"Steel";
	fire->weakAgainst[0] = (char*)"Ground";
	fire->weakAgainst[1] = (char*)"Rock";
	fire->weakAgainst[2] = (char*)"Water";
	insert(fire, hashtable);

	CombatEspece* flying = new CombatEspece;
	flying->nature = StringToPokemonType("Flying");
	flying->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		flying->strongAgainst[i] = "";
		flying->weakAgainst[i] = "";
	}
	flying->strongAgainst[0] = (char*)"Bug";
	flying->strongAgainst[1] = (char*)"Fight";
	flying->strongAgainst[2] = (char*)"Grass";
	flying->weakAgainst[0] = (char*)"Electric";
	flying->weakAgainst[1] = (char*)"Ice";
	flying->weakAgainst[2] = (char*)"Rock";
	insert(flying, hashtable);

	CombatEspece* ghost = new CombatEspece;
	ghost->nature = StringToPokemonType("Ghost");
	ghost->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		ghost->strongAgainst[i] = "";
		ghost->weakAgainst[i] = "";
	}
	ghost->strongAgainst[0] = (char*)"Ghost";
	ghost->strongAgainst[1] = (char*)"Psychic";
	ghost->weakAgainst[0] = (char*)"Dark";
	ghost->weakAgainst[1] = (char*)"Ghost";
	insert(ghost, hashtable);

	CombatEspece* grass = new CombatEspece;
	grass->nature = StringToPokemonType("Grass");
	grass->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		grass->strongAgainst[i] = "";
		grass->weakAgainst[i] = "";
	}
	grass->strongAgainst[0] = (char*)"Ground";
	grass->strongAgainst[1] = (char*)"Rock";
	grass->strongAgainst[2] = (char*)"Water";
	grass->weakAgainst[0] = (char*)"Bug";
	grass->weakAgainst[1] = (char*)"Fire";
	grass->weakAgainst[2] = (char*)"Flying";
	grass->weakAgainst[3] = (char*)"Ice";
	grass->weakAgainst[4] = (char*)"Poison";
	insert(grass, hashtable);

	CombatEspece* ground = new CombatEspece;
	ground->nature = StringToPokemonType("Ground");
	ground->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		ground->strongAgainst[i] = "";
		ground->weakAgainst[i] = "";
	}
	ground->strongAgainst[0] = (char*)"Electric";
	ground->strongAgainst[1] = (char*)"Fire";
	ground->strongAgainst[2] = (char*)"Poison";
	ground->strongAgainst[3] = (char*)"Rock";
	ground->strongAgainst[4] = (char*)"Steel";
	ground->weakAgainst[0] = (char*)"Grass";
	ground->weakAgainst[1] = (char*)"Ice";
	ground->weakAgainst[2] = (char*)"Water";
	insert(ground, hashtable);

	CombatEspece* ice = new CombatEspece;
	ice->nature = StringToPokemonType("Ice");
	ice->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		ice->strongAgainst[i] = "";
		ice->weakAgainst[i] = "";
	}
	ice->strongAgainst[0] = (char*)"Dragon";
	ice->strongAgainst[1] = (char*)"Flying";
	ice->strongAgainst[2] = (char*)"Grass";
	ice->strongAgainst[3] = (char*)"Ground";
	ice->weakAgainst[0] = (char*)"Fight";
	ice->weakAgainst[1] = (char*)"Fire";
	ice->weakAgainst[2] = (char*)"Rock";
	ice->weakAgainst[3] = (char*)"Steel";
	insert(ice, hashtable);

	CombatEspece* normal = new CombatEspece;
	normal->nature = StringToPokemonType("Normal");
	normal->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		normal->strongAgainst[i] = "";
		normal->weakAgainst[i] = "";
	}
	normal->weakAgainst[0] = (char*)"Fight";
	insert(normal, hashtable); // correction ici.

	CombatEspece* poison = new CombatEspece;
	poison->nature = StringToPokemonType("Poison");
	poison->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		poison->strongAgainst[i] = "";
		poison->weakAgainst[i] = "";
	}
	poison->strongAgainst[0] = (char*)"Fairy";
	poison->strongAgainst[1] = (char*)"Grass";
	poison->weakAgainst[0] = (char*)"Ground";
	poison->weakAgainst[1] = (char*)"Psychic";
	insert(poison, hashtable);

	CombatEspece* psychic = new CombatEspece;
	psychic->nature = StringToPokemonType("Psychic");
	psychic->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		psychic->strongAgainst[i] = "";
		psychic->weakAgainst[i] = "";
	}
	psychic->strongAgainst[0] = (char*)"Fight";
	psychic->strongAgainst[1] = (char*)"Poison";
	psychic->weakAgainst[0] = (char*)"Bug";
	psychic->weakAgainst[1] = (char*)"Dark";
	psychic->weakAgainst[2] = (char*)"Ghost";
	insert(psychic, hashtable);

	CombatEspece* rock = new CombatEspece;
	rock->nature = StringToPokemonType("Rock");
	rock->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		rock->strongAgainst[i] = "";
		rock->weakAgainst[i] = "";
	}
	rock->strongAgainst[0] = (char*)"Bug";
	rock->strongAgainst[1] = (char*)"Fire";
	rock->strongAgainst[2] = (char*)"Flying";
	rock->strongAgainst[3] = (char*)"Ice";
	rock->weakAgainst[0] = (char*)"Fight";
	rock->weakAgainst[1] = (char*)"Grass";
	rock->weakAgainst[2] = (char*)"Ground";
	rock->weakAgainst[3] = (char*)"Steel";
	rock->weakAgainst[4] = (char*)"Water";
	insert(rock, hashtable);

	CombatEspece* steel = new CombatEspece;
	steel->nature = StringToPokemonType("Steel");
	steel->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		steel->strongAgainst[i] = "";
		steel->weakAgainst[i] = "";
	}
	steel->strongAgainst[0] = (char*)"Fairy";
	steel->strongAgainst[1] = (char*)"Ice";
	steel->strongAgainst[2] = (char*)"Rock";
	steel->weakAgainst[0] = (char*)"Fight";
	steel->weakAgainst[1] = (char*)"Fire";
	steel->weakAgainst[2] = (char*)"Ground";
	insert(steel, hashtable);

	CombatEspece* water = new CombatEspece;
	water->nature = StringToPokemonType("Water");
	water->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		water->strongAgainst[i] = "";
		water->weakAgainst[i] = "";
	}
	water->strongAgainst[0] = (char*)"Fire";
	water->strongAgainst[1] = (char*)"Ground";
	water->strongAgainst[2] = (char*)"Rock";
	water->weakAgainst[0] = (char*)"Electric";
	water->weakAgainst[1] = (char*)"Grass";
	insert(water, hashtable);

	return hashtable;
};

void combat(Pokedex* pokedex, CombatHash* combatHash, EspecePokemon bestiaire[]) {
	short index, turn;
	CombatEspece* point1, *point2;
	PokemonType type1, type2;
	Pokemon *pok1, *pok2;
	short damage1 = 30, damage2 = 30;
	int i=0;
	short round = 1;

	cout << "\tChoissisez les pokemons qui vont se battre" << endl;
	cout << endl;
	cout << "\tPokemon 1: " << endl;
	cin >> index;
	pok1 = &pokedex->mesPokemons[index];
	cout << endl;
	cout << "\tPokemon 2: " << endl;
	cin >> index;
	pok2 = &pokedex->mesPokemons[index];
	cout << endl;
	char* key1, * key2;

	random_device rd;		//On a besoin pour choisir un nombre au hassard
	mt19937 eng(rd());

	uniform_int_distribution<int> tirage_aleatoire(1, 2);

	turn = tirage_aleatoire(eng);	//On choisit aléatoirement qui commence

	//On détermine lequel des deux est plus fort

	type1 = bestiaire[recherchePokemon(*pok1, bestiaire)].type;
	type2 = bestiaire[recherchePokemon(*pok2, bestiaire)].type;

	key1 = pokemonTypeToString(type1);
	key2 = pokemonTypeToString(type2);

	point1 = get(combatHash, key1);	
	point2 = get(combatHash, key2);

	

	for (i = 0; i < 5; i++) {
		if (strcmp(key2, point1->strongAgainst[i]) == 0 || strcmp(key1, point2->weakAgainst[i]) == 0) {	//Cas où le pokemon 1 est plus fort que le pokemon 2
			damage1 = damage1 * 3;
		}
		else if (strcmp(key1, point2->strongAgainst[i]) == 0 || strcmp(key2, point1->weakAgainst[i]) == 0) {	//Cas où le pokemon 2 est plus fort que le pokemon 1
			damage2 = damage2 * 3;
		}
	}

	do {
		cout << "\tRound: " << round << " FIGHT!!" << endl;
		if (turn == 1) {	//Le pokemon 1 
			cout << "\t-------------------------------------------------" << endl;
			cout << endl;
			cout << "\tPV  "<< pok1->nom << ": " << pok1->PV << " | PV " << pok2->nom << ": " << pok2->PV - damage1 << endl;
			pok2->PV -= damage1;
 			if (pok2->PV <= 0)
				break;
			cout << endl;
			cout << "\t-------------------------------------------------" << endl;
			cout << "\tPV " << pok1->nom << ": " << pok1->PV - damage2 << " | PV " << pok2->nom << ": " << pok2->PV << endl;
			pok1->PV -= damage2;
			cout << endl;
		}
		else {
			cout << "\t-------------------------------------------------" << endl;
			cout << endl;
			cout << "\tPV " << pok1->nom << ": " << pok1->PV - damage2 << " | PV " << pok2->nom << ": " << pok2->PV << endl;
			pok1->PV -= damage2;
			if (pok1->PV <= 0)
				break;
			cout << endl;
			cout << "\t-------------------------------------------------" << endl;
			cout << "\tPV " << pok1->nom << ": " << pok1->PV << " | PV " << pok2->nom << ": " << pok2->PV - damage1 << endl;
			pok2->PV -= damage1;
			cout << endl;
		}
		round++;
	} while (pok1->PV >= 0 && pok2->PV >= 0);

	if (pok1->PV <= 0) {
		pok1->PV = 0;
		cout << "\t" << pok2->nom << " est le vainqueur!" << endl;
		cout << "\t--------------------------------" << endl;
	}
	else {
		pok2->PV = 0;
		cout << "\t" << pok1->nom << " est le vainqueur!" << endl;
		cout << "\t--------------------------------" << endl;
	}
};