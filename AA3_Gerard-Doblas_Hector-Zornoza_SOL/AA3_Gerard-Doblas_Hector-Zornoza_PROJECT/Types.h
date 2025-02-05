#pragma once
#include "Constantes.h"

struct Coord
{
	int lastX = 0;
	int lastY = 0;
	int countBoxesX = 5;
	int	countBoxesY = 3;
	short PossibleCoordX[NUM_COLS];
	short PossibleCoordY[NUM_ROWS];
	void Coords();
};