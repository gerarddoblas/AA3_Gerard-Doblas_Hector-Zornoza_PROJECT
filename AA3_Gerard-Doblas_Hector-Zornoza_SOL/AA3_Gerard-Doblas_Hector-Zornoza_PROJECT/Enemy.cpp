#include "Enemy.h"

void Enemy::EnemySpawn(Coord& co, Chest& c,Player& p, int* x, int* y)
{

	co.gotoxy(0, 0);
	if (p.agility == 3)
		enemyInMap = 0;
	if (enemyInMap != enemys)
	{
		while (enemyInMap < enemys)
		{
			actualEnemy = false;
			actualChest = false;
			int randomEnemyX = rand() % NUM_COLS;
			int randomEnemyY = rand() % NUM_ROWS;

			*x = co.PossibleCoordX[randomEnemyX];
			*y = co.PossibleCoordY[randomEnemyY];

			for (int i = 0; i < CHESTS; i++)
			{
				if (*x == c.arrChestX[i] && *y == c.arrChestY[i])
				{
					actualChest = true;
					break;
				}
			}
			for (int i = 0; i < enemyInMap; i++)
			{
				if (*x == arrEnemyX[i] && *y == arrEnemyY[i])
				{
					actualEnemy = true;
					break;
				}
			}
			if (*x != p.playerX && *y != p.playerY && !actualEnemy && !actualChest)
			{
				arrEnemyX[enemyInMap] = *x;
				arrEnemyY[enemyInMap] = *y;
				co.gotoxy(*x, *y);
				enemyInMap++;
				printf("%c", enemy);
			}
		}
	}
	else
	{
		for (int i = 0; i < enemys; i++)
		{
			co.gotoxy(arrEnemyX[i], arrEnemyY[i]);
			printf("%c", enemy);
		}
	}
}