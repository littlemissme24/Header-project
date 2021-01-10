#include "Character.h"

Character::Character()
{

	// variables
playerRace = { "human", "elf", "orc", "khajiit", "fairy" };

characterName = "";
characterRace = "";
characterSex = "";

level = 1;
currentXP = 0;
baseXP = 100;
XP_4_NextLevel = baseXP;
health = 0;
totalHealth = 0;
maxHealth = 0;
heal = 0;
 maxLevel = 50;
 minLevel = 1;
}
void Character::characterCreation() {



	//Character creation
	cout << "Please enter what you want your chatacters name to be : " << endl;
	cin >> characterName;
	cout << "Please input what you want " << characterName << "'s race to be :" << endl;
	cout << "Human" << endl;
	cout << "Elf" << endl;
	cout << "Orc" << endl;
	cout << "Khajiit" << endl;
	cout << "Fairy" << endl;
	cout << "Enter your race below" << endl;
	cin >> characterRace;
	//Makes anything entered, lower case.
	for_each(characterRace.begin(), characterRace.end(), [](char& c) {
		c = ::tolower(c);
		});
	for (int i = 0; i < sizeof(playerRace); i++) {
		if (characterRace == "human") {
			health = 90;
			break;
		}
		if (characterRace == "elf") {
			health = 80;
			break;
		}
		if (characterRace == "Orc") {
			health = 120;
			break;
		}
		if (characterRace == "Khajiit") {
			health = 100;
			break;
		}
		if (characterRace == "fairy") {
			health = 85;
			break;
		}
		else
		{
			health = 100;
			break;
		}
	}

	cout << "Please input what you want " << characterName << "'s sex to be :" << endl;
	cin >> characterSex;

	// Add loading screen 
	cout << "Hang tight while we are creating your character." << endl;
	Sleep(500);
	system("cls");

	cout << "Hang tight while we are creating your character.." << endl;
	Sleep(500);
	system("cls");

	cout << "Hang tight while we are creating your character..." << endl;
	Sleep(500);
	system("cls");

	cout << "Hang tight while we are creating your character...." << endl;
	Sleep(500);
	system("cls");


	totalHealth = health;
	maxHealth = totalHealth;
}