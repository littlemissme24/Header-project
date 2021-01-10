/* Brittney Tollison
01/06/2021
Assignment - Header and Source Code files for Projects*/

#include"character.h"
//functions
void mainHub();
void combat();
void characterMoving();
void combatHub();
void createMonster();
void levelUp();

// Variables
string monsterName[] = { "Siren", "Evil Fairy", "Your Ex", "Dragon", "Gargoyle", "Vampire", "Warewolf" };
string currentMonster = "";

int currentMonsterName = 6;
int monsterHp = 0;
int monsterXp = 0;
int monsterLevel = 0;

int decision;
Character character;

int main()
{
// Calls function
character.characterCreation();
mainHub();
characterMoving();
return 0;
}
// added character. so var can get information from other files.
void mainHub() {
	Sleep(1000);
	system("cls");
	cout << "Name: " << character.characterName << "		Health:" << character.totalHealth << endl;
	cout << "Sex: " << character.characterSex << "        Characters Race: "<< character.characterRace<<endl;
	cout << "Chatacter Level: " << character.level << endl;
	cout << "Current XP: " << character.currentXP << endl;
	cout << "XP needed to Level Up!: " << character.XP_4_NextLevel << endl << endl << endl;
	characterMoving();
}

void combatHub() {
	Sleep(1000);
	system("cls");
	cout << "Name: " << character.characterName << "		-		Monsters Name : " << currentMonster << endl;
	cout << "Health:" << character.totalHealth << "		-		Monster Health: " << monsterHp  <<endl;
	cout << "Sex: " << character.characterSex << "		-		Monster Level: " << monsterLevel <<endl;
	cout << "Chatacter Level: " << character.level << endl;
	cout << "Current XP: " << character.currentXP << endl;
	cout << "XP needed to Level Up!: " << character.XP_4_NextLevel << endl << endl << endl;
	
}

void combat() {
	combatHub();
	int playerAttack;
	int playerDamage = 8 * character.level / 2;
	int monsterAttack = 6 * monsterLevel / 2;
	if (character.totalHealth >= 1 && monsterHp >= 1) {
		cout << " 1. Attact the " << currentMonster << endl;
		cout << " 2. Block the " << currentMonster << endl;
		cout << " 3. Run away from the " << currentMonster << endl;
		cin >> playerAttack;

		if (playerAttack == 1) {
			// Attact the monster
			cout << "Attacking......you did  " << playerDamage << " damage to the " << currentMonster << endl;
			monsterHp = monsterHp - playerDamage;
			Sleep(4000);
			combatHub();
			if (monsterHp >= 1) {
				cout << "Monster is now attacking..." << endl;
				character.totalHealth = character.totalHealth - monsterAttack;
				cout << " The monster did " << monsterAttack << " damage to you. " << endl;
				if (character.totalHealth <= 0) {
					character.totalHealth = 0;
					system("cls");
					cout << " YOU DIED!!!!\n You were level " << character.level << " and you got killed by " << currentMonster << endl;
					Sleep(3000);
					exit(0);
				}
			}
			else if (monsterHp <= 0) {
				monsterHp = 0;
				cout << "You have killed " << currentMonster << ", you have now received: " << monsterXp << "XP"<< endl;
				
				if (character.level != character.maxLevel) {
					character.currentXP = character.currentXP + monsterXp;
					levelUp();
				}
				Sleep(3000);
				mainHub();
			}
			Sleep(1000);
			combat();
		}
		else if (playerAttack == 2) {
			// Block the monster
			cout << " Now blocking attacks from " << currentMonster << endl;
			int i = rand() % 100 + 1;
			if (i >= 50) {
				cout << " You have blocked the incoming attack " << endl;
				character.heal = character.level * 10 / 2;
				cout << " You have been healed for " << character.heal << endl;
				character.totalHealth += character.heal;
				combat();
			}
			else {
				cout << " You have failed to block the incomming attack " << endl;
				character.totalHealth -= monsterAttack;
				cout << "You were hit for " << monsterAttack << " damage. Your current health is " << character.totalHealth << endl;
				Sleep(3000);
				combat();
			}
		}
		else if (playerAttack == 3) {
			//Run away
			cout << "You decide to run away" << endl;
			int x = rand() % 100 + 1;
			if (x >= 25) {
				cout << " You successfully run away." << endl;
				mainHub();
			}
			else {
				cout << "You tripped while running away and the monster has gotten a criticle hit off " << endl;
				character.totalHealth -= monsterAttack + 10;
				cout << "The monster hit you for " << monsterAttack + 10<< " damage. You current health is "<< character.totalHealth << endl;
				Sleep(3000);
					combat();
			}

		}
		}
	else {
		cout << " That was a invalid decision" << endl;
		Sleep(3000);
		combat();
	}

}

void characterMoving()
{
	cout << "1. Walk forward. " << endl;
	cout << "2. Take a nap." << endl;
	cout << "3. Turn around and go back." << endl;
	cin >> decision;
	if (decision == 1) {
		int temp = rand() % 100 + 1;
		cout << " You begin stepping forward to contine along the path." << endl;
		if (temp >= 50) {
			// The chatacter encounter a monster
			createMonster();
			string tempName = monsterName[rand() % currentMonsterName];
			cout << "A " << tempName << " has appeared. Prepare to engage!" << endl;
			currentMonster = tempName;
			Sleep(4000);
			combat();
		}
		else 
		cout << "On your walk, you found nothing interesting" << endl;
		Sleep(1300);
		mainHub();
	}
	else if (decision == 2) {
		cout << " You find a nice tree to set up camp so you can take a nap! " << endl;
		if (character.totalHealth <= 99) {
			character.totalHealth += 10 * character.level;
		}
		cout << "You have healed while taking a nap, your health is now: " << character.totalHealth << endl;
		Sleep(5000);
		mainHub();
	}
	else if (decision == 3) {
		int temp = rand() % 100 + 1;
		cout << " You turn around and continue along the path." << endl;
		if (temp >= 50) {
			// The chatacter encounter a monster
			createMonster();
			string tempName = monsterName[rand() % currentMonsterName];
			cout << "A " << tempName << " has appeared. Prepare to engage!" << endl;
			currentMonster = tempName;
			Sleep(1200);
			combat();
		}
		else {
			cout << " That was a invalid decision" << endl;
			Sleep(700);
			characterMoving();
		}
	}
}

void levelUp() {
	if (character.currentXP >= character.XP_4_NextLevel) {
		character.XP_4_NextLevel += floor(character.level + 30 * pow(2, character.level / 7));
		character.totalHealth = floor(character.totalHealth + 15 * pow(2, character.level / 8));
	
		if (character.level >= character.minLevel && character.level <= character.maxHealth) {
			character.level++;
		}
		else {
			character.level = 50;
		}
		character.maxHealth = character.totalHealth;
		cout << "You have now leveled up! You are now level: " << character.level << endl;
		cout << " Your health has now increased by 15 points! You max health is now: " << character.totalHealth << endl;
		Sleep(3000);
		levelUp();

	}
	Sleep(2000);
	mainHub();
}

void createMonster()
{
	monsterHp = 30;
	monsterLevel = (rand() % 3) + character.level;
	//Make sure monsters level is never 0
	if (monsterLevel == 0) {
		monsterLevel = (rand() % 3) + character.level;
	}
	//Makes sure the monsters health is not to high or low
	monsterHp = (rand() % 30) * monsterLevel;
	//Make sure monsters Health is never 0
	if (monsterHp == 0){
	monsterHp = (rand() % 30) * character.totalHealth;
}
monsterXp = monsterHp;

}