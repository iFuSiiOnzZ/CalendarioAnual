#include "CalendarioMensual.h"
#include <string.h>

int CalendarioMensual::EsBisiesto(VectorDiasMes &diasMes, int anno)
{
    int esBisiesto = ((anno % 4 == 0 && anno % 100 != 0) || anno % 400 == 0);
    if(esBisiesto){ diasMes[1]++; }
    return(esBisiesto);
}

int CalendarioMensual::CalcularDiaMes(VectorModulosMesInfo &modA, int esBisiesto, int anno, int mes, int dia)
{
    int d = ((anno - 1) % 7 + ((anno - 1) / 4 - 3 * ((anno - 1) / 100 + 1) / 4) % 7 + modA[esBisiesto][mes] % 7 + dia % 7) % 7;
    if(0 != d){ d--; } else{ d = 6; }
    return(d);
}

int CalendarioMensual::PonerFechas(int diasMes, int primerDia)
{
    for(int dia = 0; dia < diasMes; dia++)
    {
        m_MesDias[primerDia + dia] = dia + 1;
    }

    return 1;
}

void CalendarioMensual::InitCalendarioMensual()
{
    for(int dia = 0; dia < nFILES * nCOLUMNES; dia++)
    {
        m_MesDias[dia] = '.';
    }

    m_CalendarioMensualSig = 0;
}

void CalendarioMensual::GenerarCalendarioMensual(int mes, int anno, PantallaPtr pantallPtr)
{
    //http://es.wikibooks.org/wiki/Algoritmia/Algoritmo_para_calcular_el_d%C3%ADa_de_la_semana
    //http://es.wikibooks.org/wiki/Algoritmo_bisiesto

    VectorDiasMes diasMes = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int esBisiesto = EsBisiesto(diasMes, anno);

    VectorModulosMesInfo modA = {{0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5}, {0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6}};
    int d = CalcularDiaMes(modA, esBisiesto, anno, mes, 1);
    int noUtil = PonerFechas(diasMes[mes], d);

    VectorNombreMes nombreMes =  {
        "ENERO",   "FEBRERO",   "MARZO",
        "ABRIL",   "MAYO",      "JUNIO",
        "JULIO",   "AGOSTO",    "SEPTIEMBRE",
        "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"
    };

    pantallPtr->PonerMes(mes, anno, m_MesDias, nombreMes[mes]);
}
