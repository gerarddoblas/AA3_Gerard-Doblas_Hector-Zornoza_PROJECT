#include "Chest.h"

void Chest::ChestRewards(Player& p) 
{
	Gears = rand()%11;
	goldChest = rand() % (MAX_GOLD - MIN_GOLD) + MIN_GOLD;
	switch (Gears)
	{
	case 1:
		printf("                > Richard’s Hatred  +20 Health +40 Stamina +1 Agility");
		p.maxHP = p.maxHP + 20; 
		p.maxSTAM = p.maxSTAM + 40; 
		p.agility++; 
		p.gold = p.gold + goldChest + 200;
		break;
	case 2:
		printf("                > Swift boots  +20 Health +40 Stamina +1 Agility");
		p.maxHP = p.maxHP - 10;
		p.hp = p.hp - 10;
		p.maxSTAM = p.maxSTAM - 5;
		p.stam= p.stam - 5;
		p.agility++;
		p.gold = p.gold + goldChest + 10;
		break;
	case 3:
		printf("                > White Powder  -20 Health +20 Stamina +1 Agility");
		p.maxHP = p.maxHP - 20;
		p.hp = p.hp - 20;
		p.maxSTAM = p.maxSTAM + 20;
		p.agility++;
		p.gold = p.gold + goldChest + 150;
		break;
	case 4:
		printf("                > Radev's Mug  -20 Health -40 Stamina -1 Agility");
		p.maxHP = p.maxHP - 20;
		p.hp = p.hp - 20;
		p.maxSTAM = p.maxSTAM - 40;
		p.stam = p.stam - 40;
		p.agility--;
		p.gold = p.gold + goldChest - 300;
		break;
	case 5:
		printf("                > Raven feather  -10 Health +2 Agility");
		p.maxHP = p.maxHP - 10;
		p.hp = p.hp - 10;
		p.agility = p.agility + 2;
		p.gold = p.gold + goldChest + 50;
		break;
	case 6:
		printf("                > Red Mushroom  +20 Health");
		p.maxHP = p.maxHP + 30;
		p.gold = p.gold + goldChest + 170;
		break;
	case 7:
		printf("                > Ugly Facemask  +5 Health");
		p.maxHP = p.maxHP + 5;
		p.gold = p.gold + goldChest + 10;
		break;
	case 8:
		printf("                > Broken Shield  +10 Health");
		p.maxHP = p.maxHP + 10;
		p.gold = p.gold + goldChest + 25;
		break;
	case 9:
		printf("                > Green mushroom  -10 Stamina ");
		p.maxSTAM = p.maxSTAM - 10;
		p.stam = p.stam - 10;
		p.gold = p.gold + goldChest - 50;
		break;
	case 10:
		printf("                > Naughty book  +7 Stamina");
		p.maxSTAM = p.maxSTAM + 7;
		p.gold = p.gold + goldChest + 69;
		break;
	default:
		break;
	}
}
void Chest::PossiblePotion(Player& p)
{
	possibility = rand() % 101;

	if (possibility <= 25)
	{
		printf("        > The Chest contains a potion!\n");
		if (p.potions == MAX_POTIONS)
		{
			printf("                > You already have max potions!\n");
		}
		else 
		{
			printf("                >  > You Grab the potion\n");
			p.potions++;
		}
	}
}

void Chest::ChestsSpawn(Coord& co,Player& p, int* x, int* y)
{
	co.gotoxy(0, 0);
	ChestsInMap;
	if (ChestsInMap != CHESTS)
	{
	
		while (ChestsInMap < CHESTS)
		{
			int randomChestX = rand() % NUM_COLS;
			int randomChestY = rand() % NUM_ROWS;

			*x = co.PossibleCoordX[randomChestX];
			*y = co.PossibleCoordY[randomChestY];

			for (int i = 0; i < ChestsInMap; i++)
			{
				if (arrChestX[i] == *x && arrChestY[i] == *y)
				{
					actualChest = true;
					break;
				}
			}
			if (*x != p.playerX && *y != p.playerY && !actualChest)
			{
				arrChestX[ChestsInMap] = *x;
				arrChestY[ChestsInMap] = *y;
				isLooted[ChestsInMap] = false;
				co.gotoxy(*x, *y);
				ChestsInMap++;
				printf("%c", chest);
			}
		}
	}
	else
	{
		for (int i = 0; i < CHESTS; i++)
		{
			if (p.playerX == arrChestX[i] && p.playerY == arrChestY[i] && !isLooted[i])
			{
				isLooted[i] = true;
				arrChestX[i] = -1;
				arrChestX[i] = -1;
				sumChests += arrChestX[i];
			}
			else if (arrChestX[i] != -1 && arrChestY[i] != -1 && !isLooted[i])
			{
				co.gotoxy(arrChestX[i], arrChestY[i]);
				printf("%c", chest);
			}
		}
	}
}
