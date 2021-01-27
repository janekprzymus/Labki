#ifndef NEGAMAX_H
#define NEGAMAX_H

#include "logika.h"
#include "ocena.h"
#include "ruch.h"

int negamax(plansza *a, int glebokosc, int alfa, int beta){
    if(ocena(a,0)!=1 || glebokosc==0)
        return(ocena(a,0));
    listaruchow *l=NULL;
    l = mozliwosci(a,l);
    for(; l; l=l->nast){
        plansza dziecko = ruch(a);
        int nowa_ocena = -negamax(&dziecko, glebokosc-1, -beta, -alfa);
        if(nowa_ocena > alfa)
            alfa = nowa_ocena;
        if(alfa >= beta){
            zniszczliste(l);
            return beta;
        }
    }
    zniszczliste(l);
    return alfa;
}

plansza *negamax_ruch(plansza *b){
    int max = -100;
    int obecny = 0;
    plansza *a=b;

    listaruchow *l=NULL;
    l = mozliwosci(a,l);
    for(; l; l=l->nast){
        obecny = negamax(a, 4, -100, 100);
        if(obecny>max){
            max=obecny;
            a->ruch_x = l->ruch_x;
            a->ruch_y = l->ruch_y;
        }
    }
    zniszczliste(l);
    printf("Bot wykonuje ruch: x: %d, y: %c\n", a->ruch_x+1, nazwy_kolumn[a->ruch_y]);
    return a;
}


#endif