#pragma once

#include "Constantes.h"
#include "Player.h"

struct Chest
{
	Player p;
public:
	int goldChest;
	void GoldObtain();
	void ChestLogic(Player& p);
	void PossiblePotion(Player& p);
	void Input(Player& p);
private:
	int possibility;
	int Gears;
};