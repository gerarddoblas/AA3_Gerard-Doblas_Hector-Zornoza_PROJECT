#include <cstdlib>
#include <cstdio>
#include "Map.h"
#include "Character.h"
#include "Enemy.h"
#include <Windows.h> //Preguntar si se puede usar

enum class MainManager
{
	FIGHTING,

	DUNGEON,

	CHEST,

	GAMEOVER
};

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
	printf("____________________\n");
	printf("\n");
	printf("W A S D -> Move\n");
	printf("P -> Potion\n");
	printf("\n");
	printf("Enter your action: ");
}

void ShowHUDFighting(MainManager& currentScene, Character& c)
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

void CharacterMove() 
{

}

void main()
{
	srand(time(NULL));

	MainManager currentScene = MainManager::FIGHTING;

	Enemy e;

	Character c;

	Map map;

	bool gameIsOver = false;
	bool MapWrite = false;
	//while (!gameIsOver) {
	switch (currentScene)
	{
	case MainManager::FIGHTING:
		ShowHUDFighting(currentScene, c);
		break;
	case MainManager::DUNGEON:
		ShowFirstHUDDungeon(currentScene);
		map.SetMap();
		ShowLastHUDDungeon(currentScene);
		break;
	case MainManager::CHEST:
		ShowHUDChest(currentScene);
		break;
	}
	//}

}
