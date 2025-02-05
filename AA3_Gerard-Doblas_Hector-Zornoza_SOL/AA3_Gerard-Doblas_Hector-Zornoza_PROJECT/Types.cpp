#include "Types.h"

void Coord::Coords()
{

	for (int i = 0; i < NUM_COLS; ++i)
	{
		if (i == 0)
		{
			PossibleCoordX[i] = 2;
		}
		else {
			PossibleCoordX[i] = 2 + countBoxesX;
			countBoxesX = countBoxesX + 5;
		}
	}

	for (int j = 0; j < NUM_ROWS; ++j)
	{
		if (j == 0)
		{
			PossibleCoordY[j] = 9;
		}
		else {
			PossibleCoordY[j] = 9 + countBoxesY;
			countBoxesY = countBoxesY + 3;
		}
	}

}