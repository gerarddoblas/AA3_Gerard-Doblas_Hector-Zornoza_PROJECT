#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <vector>
#include "Map.h"
#include "Player.h"														//El Game Manager y el cambiar el std:: vector, El Game Over y Victory, que no se impriman sobre ellos mimos, que deje de re imprimirse cada vez que se hace system lfs
#include "Enemy.h"
#include "Constantes.h"
#include "Chest.h"
#include "Combat.h"
#include "Types.h"
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
	c.ChestRewards(p);
	printf("\n");
	c.PossiblePotion(p);
	printf("____________________________________\n");
	printf("\n");
	printf("Enter any character to continue...");
	
}

void ShowHUDGameover(Player& p)
{
	if (p.hp <= 0)
	{
		printf("------ GAME OVER ------\n");
		printf("\n");
		printf("");
		printf("\n");
		printf("");
	}
	else if (p.hp == 0)
	{

	}
}

void ChestSpawn(Map& m, Coord& co, int* x,int* y)
{
	int actuallyChests = 0;
	co.Coords();
	while (actuallyChests < CHESTS)
	{
		int randomChestX = rand() % NUM_COLS;
		int randomChestY = rand() % NUM_ROWS;

		*x = co.PossibleCoordX[randomChestX];
		*y = co.PossibleCoordY[randomChestY];

		if (*x != co.lastX && *y != co.lastY)
		{
			co.lastX = *x;
			co.lastY = *y;
			gotoxy(*x, *y);
			actuallyChests++;
			printf("%C", ConversionElementChar(ElementSpawn::CHEST));
		}
	}
}
void PlayerSpawn(int& x, int& y,Player& p) 
{
	x = 12;
	y = 18;
	gotoxy(x, y);
	std::cout << p.player;
}

void main()
{
	srand(time(NULL));

	MainManager currentScene = MainManager::DUNGEON;

	Enemy e;

	Player p;

	Map m;

	Box b;

	Chest c;

	Combat f;

	Coord co;

	printf("%C", m.ConversionBoxChar(Box::VACIO));

	int x, y;
	bool gameIsOver = false;
	bool MapWrite = false;

	while (!gameIsOver) {
	switch (currentScene)
	{
	case MainManager::FIGHTING:
		ShowHUDFighting(x, y, currentScene, p);
		f.CombatChooise(p,e);
		if (p.hp == 0 && p.hp < 0)
		{
			currentScene = MainManager::GAMEOVER;
		}
		else if(e.hp == 0 || e.hp < 0)
		{
			currentScene = MainManager::DUNGEON;
		}
		system("cls");
		break;
	case MainManager::DUNGEON:

		ShowFirstHUDDungeon(currentScene, p);
		m.SetMap();
		//PlayerSpawn(x, y, p);
		ChestSpawn(m,co, &x, &y);



		ShowLastHUDDungeon(currentScene);
		system("pause");
		break;
	case MainManager::CHEST:
		ShowHUDChest(x, y, currentScene, c, p);
		break;
	case MainManager::GAMEOVER:
		
			break;
	default:
		break;
	}
	}

}
