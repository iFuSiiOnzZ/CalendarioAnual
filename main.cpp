#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "CalendarioAnual.h"

int cogerAnno()
{
    int a = 0;

    do
    {
        printf("Introduce el anno (1601.3000):");
        scanf("%u", &a); system("cls");
    }while(a<1601 || a > 3000);

    fflush(stdin);
    return(a);
}

int main()
{
    TipoCalendarioAnualPtr ptr = new CalendarioAnual;

    COORD c = { 140, 140 };
    HANDLE hConOut = GetStdHandle( STD_OUTPUT_HANDLE );
    system("MODE CON COLS=140 LINES=30");

    SetConsoleScreenBufferSize( hConOut, c );

    ptr->setPantalla(new Pantalla);

    ptr->GenerarCalendarioAnual(cogerAnno());
    ptr->Mostrar(); ptr->Destruir();

    delete ptr;

    return(EXIT_SUCCESS);
}
