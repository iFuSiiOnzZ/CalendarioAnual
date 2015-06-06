#include "Pantalla.h"

#include <stdio.h>
#include <string.h>

void Pantalla::Init()
{
    memset(m_Pantalla, 0, GRID_Y * GRID_X);
}

void Pantalla::Mostrar()
{
    for(int i = 0; i < GRID_Y; i++)
    {
        for(int j = 0; j < GRID_X; j++)
        {
            if((m_Pantalla[i][j] >= 'A' && m_Pantalla[i][j] <= 'Z') || m_Pantalla[i][j] == '=' || m_Pantalla[i][j] == '\0' || m_Pantalla[i][j] == ' ' || m_Pantalla[i][j] == '|' || (m_Pantalla[i][j] >= '0' && m_Pantalla[i][j] <= '9'))
            {
                printf("%c", m_Pantalla[i][j]);
            }
            else if(m_Pantalla[i][j] == '.')
            {
                printf("% 2c", m_Pantalla[i][j]);
            }
            else if(m_Pantalla[i][j] >= 1 && m_Pantalla[i][j] <= 31)
            {
                printf("%02d", m_Pantalla[i][j]);
            }

        }
        printf("\n");
    }
}

 void Pantalla::PonerMes(int mes, int anno, intPtr mesArray, charPtr nombreMes)
 {
    VectorHeader l1, l2, l3, sr;
    int col  = mes % 3 * 18 + 30;
    int aux  = mes % 3;
    int fila = 0;

    if(3 == mes || 4 == mes || 5 == mes){ fila = 10; }
    else if(6 == mes || 7 == mes || 8 == mes){fila = 20; }
    else if(9 == mes || 10 == mes || 11 == mes){ fila = 30; }

    strcpy(l1, "======================");
    strcpy(l2, "LU MA MI JU VI | SA DO");
    strcpy(l3, "======================");

    if(1 == aux)
    {
        col = col + 7;
    }
    else if(2 == aux)
    {
        col = col + 14;
    }

    sprintf(sr, "%d", anno);
    strcat(&m_Pantalla[fila + 0][col], nombreMes);
    strcat(&m_Pantalla[fila + 0][col + HEADER_LINE_SZ - 5], sr);

    strcat(&m_Pantalla[fila + 1][col], l1);
    strcat(&m_Pantalla[fila + 2][col], l2);
    strcat(&m_Pantalla[fila + 3][col], l3);

    if(1 == aux)
    {
        col = col - 7;
    }
    else if(2 == aux)
    {
        col = col - 14;
    }

    for(int i = 0; i < nFILES; i++)
    {
        for(int j = 0; j < nCOLUMNES; j++)
        {
            if(j == 0)
            {
                m_Pantalla[fila + 4 + i][col + j] = mesArray[i * nCOLUMNES + j];
            }
            else if(j == 5)
            {
                m_Pantalla[fila + 4 + i][col + j * 2] = '|';
                m_Pantalla[fila + 4 + i][col + j * 2 + 2] = mesArray[i * nCOLUMNES + j];
            }
            else if(j > 5)
            {
                m_Pantalla[fila + 4 + i][col + j * 2 + 2] = mesArray[i * nCOLUMNES + j];
            }
            else
            {
                m_Pantalla[fila + 4 + i][col + j * 2] = mesArray[i * nCOLUMNES + j];
            }
        }
    }
 }
