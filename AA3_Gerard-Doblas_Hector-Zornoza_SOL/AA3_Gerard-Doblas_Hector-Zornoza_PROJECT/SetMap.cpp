#include "Map.h"

void SetMap(char map[][])
{
	map[NUM_COLS][NUM_ROWS];

	for (int i = 0; i < NUM_COLS; i++)
	{
		for (int j = 0; j < NUM_ROWS; j++)
		{
			printf("[]");
		}
		printf("\n");
	}
}