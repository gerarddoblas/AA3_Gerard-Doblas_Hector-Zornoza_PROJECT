#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <vector>
#include <iostream>
#include "Map.h"
#include "Character.h"
#include "Enemy.h"
#include "Constantes.h"
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

void ShowFirstHUDDungeon(MainManager& currentScene)
{
	printf("------ DUNGEON ------\n");
	printf("\n");
	printf("E -> Enemy    P -> Player    C -> Chest\n");
	printf("\n");
	printf("Health: \n");
	printf("Potions: \n");
	printf("Moves:  \n");
}

void ShowLastHUDDungeon(MainManager& currentScene)
{
	gotoxy(0, 32);
	printf("____________________\n");
	printf("\n");
	printf("W A S D -> Move\n");
	printf("P -> Potion\n");
	printf("\n");
	printf("Enter your action: ");
}

void ShowHUDFighting(int& x, int & y, MainManager& currentScene, Character& c)
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
	printf("[=========] %d / %d HP\n", c.hp, MAX_INIT_HP);
	printf("[>>>>>>>>>] %d / %d Stamina\n", c.stam, MAX_INIT_ST);
	printf("\n");
	printf("Potions %d / %d\n", c.potions, MAX_POTIONS);
	printf("\n");
	printf("____________________________________\n");
	printf("\n");
	printf("A -> Attack\n");
	printf("D -> Defend\n");
	printf("R -> Rest\n");
	printf("P -> Potion\n");
}

void ShowHUDChest(MainManager& currentScene)
{

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

	MainManager currentScene = MainManager::DUNGEON;

	Enemy e;

	Character c;

	Map map;

	Box b;

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
		ShowHUDFighting(x, y, currentScene, c);
		Input();
		break;
	case MainManager::DUNGEON:

		ShowFirstHUDDungeon(currentScene);
		map.SetMap();
		ChestSpawn(x, y, countBoxesX, countBoxesY);

		ShowLastHUDDungeon(currentScene);
		
		//gotoxy(2, 12);
		//printf("X");
		Input();
		break;
	case MainManager::CHEST:
		ShowHUDChest(currentScene);
		Input();
		break;
	}
	}

}
