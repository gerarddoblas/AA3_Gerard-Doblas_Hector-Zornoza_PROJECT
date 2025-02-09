#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <stdio.h>
#include <time.h>
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
	COMBAT,

	DUNGEON,

	CHEST,

	GAMEOVER
};

void ShowFirstHUDDungeon(MainManager& currentScene, Player& p, Coord& co)
{
	printf("------ DUNGEON ------\n");
	printf("\n");
	printf("E -> Enemy    P -> Player    C -> Chest\n");
	printf("\n");
	printf("Health: %d / %d\n", p.hp, p.maxHP);
	printf("Potions: %d / %d\n", p.potions, MAX_POTIONS);
	printf("Moves: %d / %d\n", p.agility, MAX_AGILITY);
}

void ShowLastHUDDungeon(MainManager& currentScene, Coord& co)
{
	co.gotoxy(0, NUM_ROWS*NUM_ROWS);
	printf("____________________\n");
	printf("\n");
	printf("W A S D -> Move\n");
	printf("P -> Potion\n");
	printf("\n");
	printf("Enter your action: ");
}

void ShowHUDFighting(int& x, int& y, MainManager& currentScene, Player& p)
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
	printf("        >%d gold!\n", c.goldChest);
	printf("        > The Chest contains Gear!\n");
	c.ChestRewards(p);
	printf("\n");
	c.PossiblePotion(p);
	printf("____________________________________\n");
	printf("\n");
	printf("Enter any character to continue...");
	printf("\n");
	getchar();
	getchar();
}

void ShowHUDGameover(Player& p, Chest& c, Enemy& e)
{
	if (p.hp <= 0 && p.hp == 0)
	{
		printf("------ GAME OVER ------\n");
		printf("\n");
		printf("	> You LOST! Radev's laughing right now. Your final score is: %d", p.gold);
		printf("\n");
		printf("Thanks for playing :) Enter any character to end the game...");
	}
	else if (e.sumEnemy == -1 * e.enemys && c.sumChests == -1 * CHESTS)
	{
		printf("------ GAME OVER ------\n");
		printf("\n");
		printf("	> You WON! Radev's minions are no more. Your final score is: %d", p.gold);
		printf("\n");
		printf("Thanks for playing :) Enter any character to end the game...");

	}
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
	co.Coords();

	while (!gameIsOver) {
	switch (currentScene)
	{
	case MainManager::COMBAT:
		ShowHUDFighting(x, y, currentScene, p);
		f.CombatChooise(p,e);
		if (p.hp == 0 && p.hp < 0)
		{
			currentScene = MainManager::GAMEOVER;
		}
		else if(e.hp == 0 || e.hp < 0)
		{
			f.firstTry = 0;
			currentScene = MainManager::DUNGEON;
		}
		system("cls");
		break;
	case MainManager::DUNGEON:

		ShowFirstHUDDungeon(currentScene, p, co);
		co.gotoxy(0,7);
		m.SetMap();
		
		c.ChestsSpawn(co, p, &x, &y);
		e.EnemySpawn(co, c, p, &x, &y);
		p.PlayerSpawn(x, y, co);
		ShowLastHUDDungeon(currentScene, co);
		p.PlayerMove();
		for (int i = 0; i < CHESTS; i++)
		{
			if (p.playerX == c.arrChestX[i] && p.playerY == c.arrChestY[i])
				currentScene = MainManager::CHEST;
		}
		for (int i = 0; i < e.enemys; i++)
		{
			if (p.playerX == e.arrEnemyX[i] && p.playerY == e.arrEnemyY[i])
				currentScene = MainManager::COMBAT;
		}
		if (e.sumEnemy == - 1 * e.enemys && c.sumChests == -1 * CHESTS)
			currentScene = MainManager::GAMEOVER;
		system("cls");
		break;
	case MainManager::CHEST:
		ShowHUDChest(x, y, currentScene, c, p);
		currentScene = MainManager::DUNGEON;
		system("cls");
		break;
	case MainManager::GAMEOVER:
		ShowHUDGameover(p, c, e);
		getchar();
		gameIsOver = true;
			break;
	default:
		break;
	}
	}

}
