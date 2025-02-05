#pragma once

#include "Constantes.h"
#include "Player.h"

struct Chest
{
	Player p;
public:
	int goldChest;
	void GoldObtain();
	void CoordChest();
	void ChestRewards(Player& p);
	void PossiblePotion(Player& p);
private:

	int possibility;
	int Gears;
};