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

void ShowHUDFighting(MainManager& currentScene)
{
	printf("------ DUNGEON ------\n");
}

void ShowHUDChest(MainManager& currentScene)
{

}

void main()
{
	srand(time(NULL));

	MainManager currentScene = MainManager::DUNGEON;

	Map map;

	bool gameIsOver = false;
	bool MapWrite = false;
	//while (!gameIsOver) {
	switch (currentScene)
	{
	case MainManager::DUNGEON:
		ShowFirstHUDDungeon(currentScene);
		map.SetMap();
		ShowLastHUDDungeon(currentScene);
	}
	//}

}
