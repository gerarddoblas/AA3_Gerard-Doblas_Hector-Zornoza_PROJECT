#pragma once

struct Enemy
{
	int hp = rand() % (MAX_INIT_HP_EN - MIN_INIT_HP_EN) + MIN_INIT_HP_EN;
	int stam = rand() % (MAX_INIT_ST_EN - MIN_INIT_ST_EN) + MIN_INIT_ST_EN;
	bool isDead;
	char enemy = 'E';
};