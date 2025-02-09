#pragma once

#include "Constantes.h"
#include "Player.h"
#include "Types.h"

struct Chest
{
	Player p;
	Coord co;
public:
	int goldChest;
	int sumChests = 0;
	int arrChestX[CHESTS];
	int arrChestY[CHESTS];
	void ChestRewards(Player& p);
	void PossiblePotion(Player& p);
	void ChestsSpawn(Coord& co,Player& p, int* x, int* y);
private:
	int ChestsInMap = 0;
	bool isLooted[CHESTS] = { false };
	char chest = 'C';
	bool actualChest = false;
	int possibility;
	int Gears;
};