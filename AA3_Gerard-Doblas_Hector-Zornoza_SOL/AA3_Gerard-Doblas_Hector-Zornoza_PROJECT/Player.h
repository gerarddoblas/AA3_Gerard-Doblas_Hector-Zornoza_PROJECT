#pragma once
#include "Constantes.h"
#include "Types.h"

struct Player
{
	Coord co;
public:
	int hp = rand()% (MAX_INIT_HP - MIN_INIT_HP) + MIN_INIT_HP; // Player HP
	int maxHP = hp;
	int stam = rand()% (MAX_INIT_ST - MIN_INIT_ST) + MIN_INIT_ST; // Player stamina
	int maxSTAM = stam;
	int gold = 0; // Player money
	int agility = 3; // Player moves
	int potions = 3; // Player potions, restore 40% HP
	char player = 'P'; // Player
	int playerX = 12;
	int playerY = 12;
	void PlayerSpawn(int& x, int& y, Coord& co);
	void PlayerMove();
};