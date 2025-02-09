#pragma once
#include "Constantes.h"
#include "Types.h"
#include "Player.h"
#include "Chest.h"
struct Enemy
{
	Coord co;
	Player p;
	Chest c;
	int enemys = rand() % (7 - 5 + 1) + 5;
	int totalEnemys = enemys;
	int hp = rand() % (MAX_INIT_HP_EN - MIN_INIT_HP_EN) + MIN_INIT_HP_EN;
	int stam = rand() % (MAX_INIT_ST_EN - MIN_INIT_ST_EN) + MIN_INIT_ST_EN;
	int maxSTAM = stam;
	int maxHP = hp;
	bool isDead;
	bool actualEnemy = false;
	bool actualChest = false;
	char enemy = 'E';
	int enemyInMap = 0;
	int* arrEnemyX= (int*)malloc(totalEnemys * sizeof(int));
	int* arrEnemyY = (int*)malloc(totalEnemys * sizeof(int));
	void EnemySpawn(Coord& co, Chest& c,Player& p, int* x, int* y);
};