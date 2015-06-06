#pragma once
#include "Defines.h"
#include "Pantalla.h"



typedef struct CalendarioMensual
{
    int                 m_MesDias[nFILES * nCOLUMNES];
    CalendarioMensual  *m_CalendarioMensualSig;

    void GenerarCalendarioMensual   (int mes, int anno, PantallaPtr pantallPtr);
    void InitCalendarioMensual      ();


    int  EsBisiesto                 (VectorDiasMes &diasMes, int anno);
    int  PonerFechas                (int diasMes, int primerDia);
    int  CalcularDiaMes             (VectorModulosMesInfo &modulesMesInfo, int esBisiesto, int anno, int mes,int dia);
};

typedef CalendarioMensual *TipoCalendarioMensualPtr;

