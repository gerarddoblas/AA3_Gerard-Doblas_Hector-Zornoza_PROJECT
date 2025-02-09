#pragma once
#include "Constantes.h"
#include <Windows.h>

struct Coord
{
	int countBoxesX = 5;
	int	countBoxesY = 3;
	short PossibleCoordX[NUM_COLS];
	short PossibleCoordY[NUM_ROWS];
	void Coords();
	void gotoxy(int x, int y);
};