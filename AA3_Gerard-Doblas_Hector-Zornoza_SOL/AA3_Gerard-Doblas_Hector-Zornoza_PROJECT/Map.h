#pragma once
#include "Constantes.h"

enum class Box {
    VACIO = ' ',

    PARED = '|',

    TECHO = '_',

};

struct Map {
public:
    char ConversionBoxChar(Box boxType);
    void SetMap();
private:
    int FILAS;
    int COLUMNAS;
};