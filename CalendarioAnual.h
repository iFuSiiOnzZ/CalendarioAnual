#pragma once

#include "CalendarioMensual.h"
#include "Pantalla.h"
#include "Defines.h"

typedef struct CalendarioAnual
{
    int                m_Anno;
    Pantalla          *m_Pantalla;
    CalendarioMensual *m_CalendarioMensual;
    CalendarioAnual   *m_CalendarioAnualSig;

    void GenerarCalendarioAnual (int anno);
    void GenerarMeses           (int anno);

    void Destruir               ();
    void Mostrar                ();

    void setPantalla            (PantallaPtr pantalla);

};

typedef CalendarioAnual *TipoCalendarioAnualPtr;

