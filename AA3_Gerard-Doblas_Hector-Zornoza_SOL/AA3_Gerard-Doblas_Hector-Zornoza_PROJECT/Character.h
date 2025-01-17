#pragma once

struct Player
{
	int hp = rand()% (MAX_INIT_HP - MIN_INIT_HP) + MIN_INIT_HP; // Player HP
	int maxHP = hp;
	int stam = rand()% (MAX_INIT_ST - MIN_INIT_ST) + MIN_INIT_ST; // Player stamina
	int maxSTAM = stam;
	int gold = 0; // Player money
	int agility = 3; // Player moves
	int potions = 3; // Player potions, restore 40% HP
	char player = 'P'; // Player
};