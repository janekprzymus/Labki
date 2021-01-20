#ifndef DEF_H
#define DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define czarne 0
#define biale  1
#define puste  2
#define mozliwe 3
#define n 8

#define BIALE_ZNACZNIK    "  B  "
#define CZARNE_ZNACZNIK    "  C  "
#define PUSTE_ZNACZNIK    "     "
#define MOZLIWE_ZNACZNIK  "  .  "

typedef struct _plansza
{
int pola[n][n], ruch_x, ruch_y;
int czyjruch;
} plansza, *pplansza;

const char *nazwy_wierszy = "12345678";
const char *nazwy_kolumn = "abcdefgh";

void start(plansza *a){
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        a->pola[i][j] = puste;
    }
}
a->pola[n/2-1][n/2-1] = biale;
a->pola[n/2-1][n/2] = czarne;
a->pola[n/2][n/2] = biale;
a->pola[n/2][n/2-1] = czarne;
}

#endif