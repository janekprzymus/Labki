#include "logika.h"
#include "interfejs.h"
#include "ruch.h"
#include "negamax.h"

int main(void){
    plansza a;
    start(&a);
    wypisz(&a);
    listaruchow *l=NULL;

    char wybor_koloru[10];
    do{
        printf("Wybierz kolor, którym chcesz grać (czarny/bialy):\n");
        scanf("%s", wybor_koloru);
        if(strcmp(wybor_koloru, "bialy")==0){
            a.czyjruch=biale;
            printf("Twoje pionki są koloru białego. Komputer gra pionkami czarnymi.\n\n");
        }
        else if(strcmp(wybor_koloru, "czarny")==0){
            a.czyjruch=czarne;
            printf("Twoje pionki są koloru czarnego. Komputer gra pionkami białymi.\n\n");
        }
        else{
            printf("Wprowadzono nieprawidłowy kolor.\n");
        }
    } while(strcmp(wybor_koloru, "bialy")!=0 && strcmp(wybor_koloru, "czarny")!=0);
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