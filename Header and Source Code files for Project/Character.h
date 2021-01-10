#pragma once
#include "Header.h"
class Character
{
public:
	Character();
	string characterName;
	string characterRace;
	string characterSex;

	vector <string> playerRace;

	int level;
	int currentXP;
	int baseXP;
	int XP_4_NextLevel;
	int maxLevel;
	int minLevel;
	int health;
	int totalHealth;
	int maxHealth;
	int heal;

	// Functions


	void characterCreation();
};

