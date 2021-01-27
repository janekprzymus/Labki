#include "logika.h"
#include "interfejs.h"
#include "ruch.h"
#include "negamax.h"

int main(void){
    plansza a;
    start(&a);
    wypisz(&a);
    listaruchow *l=NULL;
    printf("Ruchy bialego:\n");
    a.czyjruch=biale;
    l=mozliwosci(&a, l);
    wypisz(&a);
    printf("Ruchy czarnego:\n");
    zmiana_gracza(&a);
    l=mozliwosci(&a, l);
    wypisz(&a);
    printf("\n");
    zmiana_gracza(&a);
    do{
    a=ruch(interface(&a, l));
    wypisz(&a);
    zmiana_gracza(&a);
    a=ruch(negamax_ruch(&a));
    wypisz(&a);
    zmiana_gracza(&a);
    } while(ocena(&a, 0)==1);
    rezultat(ocena(&a, 0));
    zniszczliste(l);
    return 0;
}