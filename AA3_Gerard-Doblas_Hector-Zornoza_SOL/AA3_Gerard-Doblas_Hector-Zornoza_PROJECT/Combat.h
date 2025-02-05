#pragma once
#include "Player.h"
#include "Enemy.h"
struct Combat {
	Player p;
	Enemy e;
private:
	char chInput;
	int playerAttack;
	float enemyAttack;
	bool Defend = false;
	bool Rest = false;
public:
	void CombatChooise(Player& p, Enemy& e);
};