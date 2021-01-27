#ifndef LISTA_RUCHOW_H
#define LISTA_RUCHOW_H

#include "def.h"

typedef struct _listaruchow{
    int ruch_x;
    int ruch_y;

    struct _listaruchow *nast;
} listaruchow;

void zniszczliste(listaruchow *l)
{
    if (l && l->nast)
        zniszczliste(l->nast);
    if (l)
        free(l);
}

listaruchow *dodaj_ruch(listaruchow *l, int x, int y){
    listaruchow *a = (listaruchow*) calloc(1, sizeof(listaruchow));
    a->ruch_x = x;
    a->ruch_y = y;
    if(l==NULL)
        return a;

    listaruchow *glowa = l;
    while(l->nast)
        l = l->nast;
    l->nast = a;
    return glowa;
}


#endif