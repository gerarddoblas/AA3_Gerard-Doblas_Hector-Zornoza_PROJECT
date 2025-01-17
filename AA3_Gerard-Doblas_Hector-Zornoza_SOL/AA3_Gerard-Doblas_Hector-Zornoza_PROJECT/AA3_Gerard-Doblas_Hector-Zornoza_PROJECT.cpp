#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <vector>
#include <iostream>
#include "Map.h"
#include "Character.h"														//El Game Manager y el cambiar el std:: vector, El Game Over y Victory, que no se impriman sobre ellos mimos
#include "Enemy.h"
#include "Constantes.h"
#include "Chest.h"
#include "Combat.h"
#include <Windows.h>
enum class MainManager
{
	FIGHTING,

	DUNGEON,

	CHEST,

	GAMEOVER
};

enum class ElementSpawn {
	PLAYER = 'P',

	ENEMY = 'E',

	CHEST = 'C',

};

char ConversionElementChar(ElementSpawn elementType)
{
	return static_cast<char>(elementType);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ShowFirstHUDDungeon(MainManager& currentScene, Player& p)
{
	printf("------ DUNGEON ------\n");
	printf("\n");
	printf("E -> Enemy    P -> Player    C -> Chest\n");
	printf("\n");
	printf("Health: %d / %d\n", p.hp, p.maxHP);
	printf("Potions: %d / %d\n", p.potions, MAX_POTIONS);
	printf("Moves: %d / %d\n", p.agility, MAX_AGILITY);
}

void ShowLastHUDDungeon(MainManager& currentScene)
{
	gotoxy(0, NUM_ROWS*NUM_ROWS);
	printf("____________________\n");
	printf("\n");
	printf("W A S D -> Move\n");
	printf("P -> Potion\n");
	printf("\n");
	printf("Enter your action: ");
}

void ShowHUDFighting(int& x, int & y, MainManager& currentScene, Player& p)
{

	printf("------ COMBAT ------\n");
	printf("\n");
	printf("--ENEMY--\n");
	printf("[=========] ? HP\n");
	printf("[>>>>>>>>>] ? Stamina\n");
	printf("\n");
	printf("---------------------\n");
	printf("\n");
	printf("-- PLAYER --\n");
	printf("[=========] %d / %d HP\n", p.hp, p.maxHP);
	printf("[>>>>>>>>>] %d / %d Stamina\n", p.stam, p.maxSTAM);
	printf("\n");
	printf("Potions %d / %d\n", p.potions, MAX_POTIONS);
	printf("\n");
	printf("____________________________________\n");
	printf("\n");
	printf("A -> Attack\n");
	printf("D -> Defend\n");
	printf("R -> Rest\n");
	printf("P -> Potion\n");
	printf("Enter your action: ");
}

void ShowHUDChest(int& x, int& y, MainManager& currentScene, Chest& c, Player& p)
{
	printf("------ CHEST ------\n");
	printf("\n");
	printf(" > You open the chest and it contains the following:\n");
	printf("\n");
	c.GoldObtain();
	printf("        >%d gold!\n", c.goldChest);
	printf("        > The Chest contains Gear!\n");
	c.ChestLogic(p);
	printf("\n");
	c.PossiblePotion(p);
	printf("____________________________________\n");
	printf("\n");
	printf("Enter any character to continue...");
	
}

void ChestSpawn(int& x,int& y, int& countBoxesX, int& countBoxesY)
{
	
		std::vector<short> PossibleChestCoordX(NUM_COLS);
		std::vector<short> PossibleChestCoordY(NUM_ROWS);
		countBoxesX = 5;
		countBoxesY = 3;
		for (int i = 0; i < NUM_COLS; ++i)
		{
			if (i == 0)
			{
				PossibleChestCoordX[i] = 2;
			}
			else {
				PossibleChestCoordX[i] = 2 + countBoxesX;
				countBoxesX = countBoxesX + 5;
			}
		}

		for (int j = 0; j < NUM_ROWS; ++j)
			if (j == 0)
			{
				PossibleChestCoordY[j] = 9;

			}
			else {
				PossibleChestCoordY[j] = 9 + countBoxesY;
				countBoxesY = countBoxesY + 3;

			}
	for (int counterChest = 0; counterChest < CHESTS; counterChest++)
	{
		int randomChestX = rand() % PossibleChestCoordX.size();
		int randomChestY = rand() % PossibleChestCoordY.size();

		x = PossibleChestCoordX[randomChestX];
		y = PossibleChestCoordY[randomChestX];
		gotoxy(x, y);
		printf("%C", ConversionElementChar(ElementSpawn::CHEST));
	}
}
void CharacterMove() 
{

}

void Input()
{
	while (std::cin.get() != '\n');
}

void main()
{
	srand(time(NULL));

	MainManager currentScene = MainManager::FIGHTING;

	Enemy e;

	Player p;

	Map map;

	Box b;

	Chest c;
	Combat co;

	printf("%C", map.ConversionBoxChar(Box::VACIO));

	int x, y;
	int countBoxesX, countBoxesY;
	bool gameIsOver = false;
	bool MapWrite = false;

	while (!gameIsOver) {
		system("cls");
	switch (currentScene)
	{
	case MainManager::FIGHTING:
		ShowHUDFighting(x, y, currentScene, p);
		co.CombatChooise(p,e);
		//Input();
		system("pause");
		break;
	case MainManager::DUNGEON:

		ShowFirstHUDDungeon(currentScene, p);
		map.SetMap();
		ChestSpawn(x, y, countBoxesX, countBoxesY);
		ShowLastHUDDungeon(currentScene);
		Input();
		break;
	case MainManager::CHEST:
		ShowHUDChest(x, y, currentScene, c, p);
		Input();
		break;
	}
	}

}
