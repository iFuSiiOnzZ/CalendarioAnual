#pragma once
#include "Defines.h"

typedef struct Pantalla
{
    char m_Pantalla[GRID_Y][GRID_X];

    void Init          ();
    void Mostrar       ();
    void PonerMes      (int mes, int anno, intPtr mesArray, charPtr nombreMes);
};

typedef Pantalla *PantallaPtr;

