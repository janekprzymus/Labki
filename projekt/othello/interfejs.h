#ifndef INTERFEJS_H
#define INTERFEJS_H

#include "ocena.h"
#include "wizualizacja.h"
#include "logika.h"

plansza * interface(plansza *b, listaruchow *l){
    char *czyj, kolumna;
    plansza *a=b;
    
    if(a->czyjruch==czarne)
        czyj="czarny";
    if(a->czyjruch==biale)
        czyj="biały";
    printf("Ruch wykonuje %s\n", czyj);
    l=mozliwosci(a, l);
    wypisz(a);

    do{
    printf("Wprowadź wykonywany ruch (w kolejnosci: wiersz 1-8, kolumna a-h; '99' aby zakończyć grę):\n");
    scanf("%d", &a->ruch_x);
    if(a->ruch_x==99){
        rezultat(ocena(a, 1));
    }
    a->ruch_x--;
    scanf("%s", &kolumna);
    for(a->ruch_y=0;a->ruch_y<n;a->ruch_y++){
        if(nazwy_kolumn[a->ruch_y]==kolumna){
            break;
        }
    }
    if(a->pola[a->ruch_x][a->ruch_y]!=mozliwe || a->ruch_x>7 || a->ruch_y>7)
        printf("Wprowadzono nieprawidłowy ruch\n");
    } while(a->pola[a->ruch_x][a->ruch_y]!=mozliwe || a->ruch_x>7 || a->ruch_y>7);

    return a;
}

#endif