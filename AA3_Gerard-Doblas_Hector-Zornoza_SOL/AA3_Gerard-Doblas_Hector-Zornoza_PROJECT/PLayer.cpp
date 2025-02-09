#include "Player.h"


void Player::PlayerSpawn(int& x, int& y, Coord& co)
{
	x = playerX;
	y = playerY;
	co.gotoxy(x, y);
	printf("%c", player);
}

void Player::PlayerMove()
{
	co.Coords();
	char move;
	scanf_s("%c", &move,1);

	switch (move)
	{
	case 'W':

		agility--;
		if (playerY != co.PossibleCoordY[0])
			playerY -= ROWS_SIZES;
		if (agility == 0)
			agility = 3;
		break;
	case 'A':

		agility--;
		if (playerX != co.PossibleCoordX[0])
			playerX -= 5;
		if (agility == 0)
			agility = 3;
		break;
	case 'S':

		agility--;
		if (playerY != co.PossibleCoordY[NUM_ROWS-1])
			playerY += ROWS_SIZES;
		if (agility == 0)
			agility = 3;
		break;
	case 'D':

		agility--;
		if (playerX != co.PossibleCoordX[NUM_COLS-1])
			playerX += 5;
		if (agility == 0)
			agility = 3;
		break;
	case 'P':
		if (potions != 0)
		{
			potions--;
			hp = hp + (maxHP * (40 / 100));
		}
		
		break;
	default:
		break;
	}
}