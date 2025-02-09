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
	int chests = CHESTS;
	int arrChestX[CHESTS];
	int arrChestY[CHESTS];
	void GoldObtain();
	void ChestRewards(Player& p);
	void PossiblePotion(Player& p);
	void ChestsSpawn(Coord& co,Player& p, int* x, int* y);
	int ChestsInMap = 0;
private:
	char chest = 'C';
	bool actualChest = false;

	int possibility;
	int Gears;
};