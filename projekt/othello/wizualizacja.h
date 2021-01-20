#ifndef WIZUALIZACJA_H
#define WIZUALIZACJA_H

#include "def.h"

void wypisz(plansza *a)
{
    printf( "     %c     %c     %c     %c     %c     %c     %c     %c\n", 
    nazwy_kolumn[0], nazwy_kolumn[1], nazwy_kolumn[2], nazwy_kolumn[3], nazwy_kolumn[4], nazwy_kolumn[5], nazwy_kolumn[6], nazwy_kolumn[7] );
    printf( "   _____ _____ _____ _____ _____ _____ _____ _____\n" );
    for ( int i=0; i<n; i++)
    {
        printf( "  |     |     |     |     |     |     |     |     |\n" );
        printf( "%c |", nazwy_wierszy[i] );
        for ( int j=0; j<n; j++)
        {
            if ( a->pola[i][j] == biale )
            {
                printf( "%s", BIALE_ZNACZNIK );
            } else if ( a->pola[i][j] == czarne )
            {
                printf( "%s", CZARNE_ZNACZNIK );
            } else if ( a->pola[i][j] == mozliwe )
            {
                printf( "%s", MOZLIWE_ZNACZNIK );
            } else
            {
                printf( "%s", PUSTE_ZNACZNIK );
            }
            printf("|");
        }
        printf( "\n" );
        printf( "  |_____|_____|_____|_____|_____|_____|_____|_____|\n" );
    }
    printf( "\n" );
}

#endif