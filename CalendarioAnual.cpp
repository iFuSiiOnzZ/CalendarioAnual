#include "CalendarioAnual.h"
#include <stdio.h>

void CalendarioAnual::GenerarMeses(int anno)
{
    TipoCalendarioMensualPtr repMes = m_CalendarioMensual;

    int mes = 1;
    TipoCalendarioMensualPtr otrosMeses = 0;

    while(mes < nMESES)
    {
        otrosMeses = new CalendarioMensual;
        otrosMeses->InitCalendarioMensual();
        otrosMeses->GenerarCalendarioMensual(mes, anno, m_Pantalla);

        repMes->m_CalendarioMensualSig = otrosMeses;
        repMes = otrosMeses;

        mes++;
    }
}

void CalendarioAnual::GenerarCalendarioAnual(int anno)
{
    TipoCalendarioMensualPtr primerMes = new CalendarioMensual;
    TipoCalendarioMensualPtr repMes = primerMes;
    m_CalendarioMensual = primerMes;

    m_CalendarioMensual->InitCalendarioMensual();
    m_CalendarioMensual->GenerarCalendarioMensual(0, anno, m_Pantalla);

    m_Anno = anno;
    GenerarMeses(anno);
}

void CalendarioAnual::Mostrar()
{
    m_Pantalla->Mostrar();
}

void CalendarioAnual::Destruir()
{
    TipoCalendarioMensualPtr temp = 0;

    while(0 != m_CalendarioMensual)
    {
        temp = m_CalendarioMensual;
        m_CalendarioMensual = m_CalendarioMensual->m_CalendarioMensualSig;

        delete temp;
        temp = 0;
    }
}

void CalendarioAnual::setPantalla(PantallaPtr pantalla)
{
    m_Pantalla = pantalla;
    m_Pantalla->Init();
}
