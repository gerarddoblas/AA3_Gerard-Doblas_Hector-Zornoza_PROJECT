#include "Map.h"

char Map::ConversionBoxChar(Box boxType)
{
	return static_cast<char>(boxType);
}
void Map::SetMap()
{
	for (int i = 0; i <= NUM_ROWS - 1; i++)
	{
		if (i == 0)
		{
			for (int p = 0; p <= NUM_COLS - 1; p++)
			{
				if (p != 0)
				{
					printf("%C", ConversionBoxChar(Box::VACIO));
				}
				for (int j = 0; j <= COLS_SIZE - 1; j++)
				{
					if (j == 0)
					{
						printf("%C", ConversionBoxChar(Box::VACIO));
					}
					printf("%C", ConversionBoxChar(Box::TECHO));
				}
			}
			printf("\n");
		}

		for (int k = 0; k <= ROWS_SIZES - 1; k++)
		{

			for (int m = 0; m <= NUM_COLS - 1; m++)
			{
				printf("%C", ConversionBoxChar(Box::PARED));

				for (int l = 0; l <= COLS_SIZE - 1; l++)
				{
					switch (k) {
					case ROWS_SIZES - 1:
						printf("%C", ConversionBoxChar(Box::TECHO));
						break;
					default:
						printf("%C", ConversionBoxChar(Box::VACIO));
					}
				}
				printf("%C", ConversionBoxChar(Box::PARED));
			}
			printf("\n");
		}
	}
}
