#include "logika.h"
#include "interfejs.h"
#include "ruch.h"

int main(void){
    plansza a;
    start(&a);
    wypisz(&a);
    plansza b;
    printf("Ruchy bialego:\n");
    a.czyjruch=biale;
    b=mozliwosci(&a);
    wypisz(&b);
    printf("Ruchy czarnego:\n");
    zmiana_gracza(&a);
    b=mozliwosci(&a);
    wypisz(&b);
    printf("\n");
    zmiana_gracza(&b);
    plansza c=ruch(interface(&b));
    wypisz(&c);
    do{
    zmiana_gracza(&c);
    c=ruch(interface(&c));
    wypisz(&c);
    } while(ocena(&c, 0)==1);
    rezultat(ocena(&c, 0));
    return 0;
}