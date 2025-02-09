#pragma once
#include "Constantes.h"
#include "Types.h"

struct Player
{
	Coord co;
public:
	int hp = rand()% (MAX_INIT_HP - MIN_INIT_HP) + MIN_INIT_HP;
	int maxHP = hp;
	int stam = rand()% (MAX_INIT_ST - MIN_INIT_ST) + MIN_INIT_ST; 
	int maxSTAM = stam;
	int gold = 0; 
	int agility = 3; 
	int potions = 3; 
	char player = 'P'; 
	int playerX = 12;
	int playerY = 12;
	void PlayerSpawn(int& x, int& y, Coord& co);
	void PlayerMove();
};