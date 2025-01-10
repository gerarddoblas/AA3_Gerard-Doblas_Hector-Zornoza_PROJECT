#pragma once

struct Character
{
	int hp = rand()% (MAX_INIT_HP - MIN_INIT_HP) + MIN_INIT_HP; // Characetr HP
	int stam = rand()% (MAX_INIT_ST - MIN_INIT_ST) + MIN_INIT_ST; // Character stamina
	int gold = 0; // Character money
	int agility = 3; // Character moves
	int potions = 3; // Character potions, restore 40% HP
	char player = 'P'; // Character 
};