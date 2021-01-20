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

void rezultat(plansza *a, int b, int c)
{    

    if((b>c)||(c==0)){
        printf("Biały wygrywa!\n");
        exit(1);
    }
    if((c>b)||(b==0)){
        printf("Czarny wygrywa!\n");
        exit(2);
    }
    if(c==b){
        printf("Remis!\n");
        exit(3);
    }
}
/*
int ocena(plansza *a, int stop)
{
    int i,j;
    int czarnych=0, bialych=0, mozliwych=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(a->pola[i][j]==biale)
                bialych++;
            if(a->pola[i][j]==czarne)
                czarnych++;
            if(a->pola[i][j]==mozliwe)
                mozliwych++;
        }
 
    if(czarnych+bialych == n*n || czarnych == 0 || bialych == 0 || mozliwych==0 || stop==1)
    {
        rezultat(a, bialych, czarnych);
        return 0; //koniec gry
    }
    else{
        return 1; //gramy dalej
    }
 
}*/

int ocena(plansza *a, int stop)
{
    int i,j;
    int czarnych=0, bialych=0, mozliwych=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(a->pola[i][j]==biale)
                bialych++;
            if(a->pola[i][j]==czarne)
                czarnych++;
            if(a->pola[i][j]==mozliwe)
                mozliwych++;
        }
 
    if(czarnych+bialych == n*n || czarnych == 0 || bialych == 0 || mozliwych==0 || stop==1)
    {
        rezultat(a, bialych, czarnych);
        if(bialych>czarnych)
        {
            return 100; // bialy win
        }
        if(czarnych>bialych)
        {
            return -100; //czarny win
        }
        if(bialych==czarnych)
        {
            return 0; //remis
        }
    }
    else{
        return 1; //gramy dalej
    }
 
}

void zmiana_gracza(plansza *a){
    a->czyjruch=(a->czyjruch+1)%2;
}

plansza mozliwosci(plansza *b)
{
    plansza a;
    a=*b;
    int i,j,x,y;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            if(a.pola[i][j]==mozliwe)
                a.pola[i][j]=puste;
        }
    if(a.czyjruch==biale){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(a.pola[i][j]==biale)
                {
                    x=i;
                    y=j;
                    while(a.pola[x-1][y]==czarne && x>0)
                    {
                        x--;
                        if(a.pola[x-1][y]==puste && x>0)
                        {
                            a.pola[x-1][y]=mozliwe;
                            break;
                        }
                        if(a.pola[x-1][y]==biale)
                            break;
                        if(a.pola[x-1][y]==mozliwe)
                        {
                            a.pola[x-1][y]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x+1][y]==czarne && x<n)
                    {
                        x++;
                        if(a.pola[x+1][y]==puste && x<n)
                        {
                            a.pola[x+1][y]=mozliwe;
                            break;
                        }
                        if(a.pola[x+1][y]==biale)
                            break;
                        if(a.pola[x+1][y]==mozliwe)
                        {
                            a.pola[x+1][y]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x][y-1]==czarne && y>0)
                    {
                        y--;
                        if(a.pola[x][y-1]==puste && y>0)
                        {
                            a.pola[x][y-1]=mozliwe;
                            break;
                        }
                        if(a.pola[x][y-1]==biale)
                            break;
                        if(a.pola[x][y-1]==mozliwe)
                        {
                            a.pola[x][y-1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x][y+1]==czarne && y<n)
                    {
                        y++;
                        if(a.pola[x][y+1]==puste && y<n)
                        {
                            a.pola[x][y+1]=mozliwe;
                            break;
                        }
                        if(a.pola[x][y+1]==biale)
                            break;
                        if(a.pola[x][y+1]==mozliwe)
                        {
                            a.pola[x][y+1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x+1][y+1]==czarne && x<n && y<n)
                    {
                        x++;
                        y++;
                        if(a.pola[x+1][y+1]==puste && x<n && y<n)
                        {
                            a.pola[x+1][y+1]=mozliwe;
                            break;
                        }
                        if(a.pola[x+1][y+1]==biale)
                            break;
                        if(a.pola[x+1][y+1]==mozliwe)
                        {
                            a.pola[x+1][y+1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x-1][y-1]==czarne && x>0 && y>0)
                    {
                        x--;
                        y--;
                        if(a.pola[x-1][y-1]==puste && x>0 && y>0)
                        {
                            a.pola[x-1][y-1]=mozliwe;
                            break;
                        }
                        if(a.pola[x-1][y-1]==biale)
                            break;
                        if(a.pola[x-1][y-1]==mozliwe)
                        {
                            a.pola[x-1][y-1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x+1][y-1]==czarne && x<n && y>0)
                    {
                        x++;
                        y--;
                        if(a.pola[x+1][y-1]==puste && x<n && y>0)
                        {
                            a.pola[x+1][y-1]=mozliwe;
                            break;
                        }
                        if(a.pola[x+1][y-1]==biale)
                            break;
                        if(a.pola[x+1][y-1]==mozliwe)
                        {
                            a.pola[x+1][y-1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x-1][y+1]==czarne && x>0 && y<n)
                    {
                        x--;
                        y++;
                        if(a.pola[x-1][y+1]==puste && x>0 && y<n)
                        {
                            a.pola[x-1][y+1]=mozliwe;
                            break;
                        }
                        if(a.pola[x-1][y+1]==biale)
                            break;
                        if(a.pola[x-1][y+1]==mozliwe)
                        {
                            a.pola[x-1][y+1]=mozliwe;
                            break;
                        }
                    }
                }

            }
    }
    if(a.czyjruch==czarne){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(a.pola[i][j]==czarne)
                {
                    x=i;
                    y=j;
                    while(a.pola[x-1][y]==biale && x>0)
                    {
                        x--;
                        if(a.pola[x-1][y]==puste && x>0)
                        {
                            a.pola[x-1][y]=mozliwe;
                            break;
                        }
                        if(a.pola[x-1][y]==czarne)
                            break;
                        if(a.pola[x-1][y]==mozliwe)
                        {
                            a.pola[x-1][y]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x+1][y]==biale && x<n)
                    {
                        x++;
                        if(a.pola[x+1][y]==puste && x<n)
                        {
                            a.pola[x+1][y]=mozliwe;
                            break;
                        }
                        if(a.pola[x+1][y]==czarne)
                            break;
                        if(a.pola[x+1][y]==mozliwe)
                        {
                            a.pola[x+1][y]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x][y-1]==biale && y>0)
                    {
                        y--;
                        if(a.pola[x][y-1]==puste && y>0)
                        {
                            a.pola[x][y-1]=mozliwe;
                            break;
                        }
                        if(a.pola[x][y-1]==czarne)
                            break;
                        if(a.pola[x][y-1]==mozliwe)
                        {
                            a.pola[x][y-1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x][y+1]==biale && y<n)
                    {
                        y++;
                        if(a.pola[x][y+1]==puste && y<n)
                        {
                            a.pola[x][y+1]=mozliwe;
                            break;
                        }
                        if(a.pola[x][y+1]==czarne)
                            break;
                        if(a.pola[x][y+1]==mozliwe)
                        {
                            a.pola[x][y+1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x+1][y+1]==biale && x<n && y<n)
                    {
                        x++;
                        y++;
                        if(a.pola[x+1][y+1]==puste && x<n && y<n)
                        {
                            a.pola[x+1][y+1]=mozliwe;
                            break;
                        }
                        if(a.pola[x+1][y+1]==czarne)
                            break;
                        if(a.pola[x+1][y+1]==mozliwe)
                        {
                            a.pola[x+1][y+1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x-1][y-1]==biale && x>0 && y>0)
                    {
                        x--;
                        y--;
                        if(a.pola[x-1][y-1]==puste && x>0 && y>0)
                        {
                            a.pola[x-1][y-1]=mozliwe;
                            break;
                        }
                        if(a.pola[x-1][y-1]==czarne)
                            break;
                        if(a.pola[x-1][y-1]==mozliwe)
                        {
                            a.pola[x-1][y-1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x+1][y-1]==biale && x<n && y>0)
                    {
                        x++;
                        y--;
                        if(a.pola[x+1][y-1]==puste && x<n && y>0)
                        {
                            a.pola[x+1][y-1]=mozliwe;
                            break;
                        }
                        if(a.pola[x+1][y-1]==czarne)
                            break;
                        if(a.pola[x+1][y-1]==mozliwe)
                        {
                            a.pola[x+1][y-1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a.pola[x-1][y+1]==biale && x>0 && y<n)
                    {
                        x--;
                        y++;
                        if(a.pola[x-1][y+1]==puste && x>0 && y<n)
                        {
                            a.pola[x-1][y+1]=mozliwe;
                            break;
                        }
                        if(a.pola[x-1][y+1]==czarne)
                            break;
                        if(a.pola[x-1][y+1]==mozliwe)
                        {
                            a.pola[x-1][y+1]=mozliwe;
                            break;
                        }
                    }
                }

            }
    }
    return a;
}

plansza * interface(plansza *b){
    char *czyj, kolumna;
    plansza *a=b;
    
    if(a->czyjruch==czarne)
        czyj="czarny";
    if(a->czyjruch==biale)
        czyj="biały";
    printf("Ruch wykonuje %s\n", czyj);
    *a=mozliwosci(a);
    wypisz(a);

    do{
    printf("Wprowadź wykonywany ruch (w kolejnosci: wiersz 1-8, kolumna a-h; '99' aby zakończyć grę):\n");
    scanf("%d", &a->ruch_x);
    if(a->ruch_x==99){
        ocena(a, 1);
        exit(-99);
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


plansza ruch(plansza *b)
{
    plansza a;
    a=*b;
    int i,j,x,y;
    i=a.ruch_x;
    j=a.ruch_y;
    
    if(a.pola[i][j]==mozliwe)
    {
        if(a.czyjruch==biale){
            a.pola[i][j]=biale;
            x=i;
            y=j;
            while(a.pola[x-1][y+1]==czarne && x>0 && y<n)
            {
                x--;
                y++;
                if(a.pola[x-1][y+1]==puste)
                    break;
                if(a.pola[x-1][y+1]==czarne)
                    a.pola[x][y]=biale;
                if(a.pola[x-1][y+1]==biale){
                    a.pola[x][y]=biale;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x+1][y+1]==czarne && x<n && y<n)
            {
                x++;
                y++;
                if(a.pola[x+1][y+1]==puste)
                    break;
                if(a.pola[x+1][y+1]==czarne)
                    a.pola[x][y]=biale;
                if(a.pola[x+1][y+1]==biale){
                    a.pola[x][y]=biale;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x+1][y-1]==czarne && x<n && y>0)
            {
                x++;
                y--;
                if(a.pola[x+1][y-1]==puste)
                    break;
                if(a.pola[x+1][y-1]==czarne)
                    a.pola[x][y]=biale;
                if(a.pola[x+1][y-1]==biale){
                    a.pola[x][y]=biale;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x-1][y-1]==czarne && x>0 && y>0)
            {
                x--;
                y--;
                if(a.pola[x-1][y-1]==puste)
                    break;
                if(a.pola[x-1][y-1]==czarne)
                    a.pola[x][y]=biale;
                if(a.pola[x-1][y-1]==biale){
                    a.pola[x][y]=biale;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x][y+1]==czarne && y<n)
            {
                y++;
                if(a.pola[x][y+1]==puste)
                    break;
                if(a.pola[x][y+1]==czarne)
                    a.pola[x][y]=biale;
                if(a.pola[x][y+1]==biale){
                    a.pola[x][y]=biale;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x][y-1]==czarne && y>0)
            {
                y--;
                if(a.pola[x][y-1]==puste)
                    break;
                if(a.pola[x][y-1]==czarne)
                    a.pola[x][y]=biale;
                if(a.pola[x][y-1]==biale){
                    a.pola[x][y]=biale;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x-1][y]==czarne && x>0)
            {
                x--;
                if(a.pola[x-1][y]==puste)
                    break;
                if(a.pola[x-1][y]==czarne)
                    a.pola[x][y]=biale;
                if(a.pola[x-1][y]==biale){
                    a.pola[x][y]=biale;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x+1][y]==czarne && x<n)
            {
                x++;
                if(a.pola[x+1][y]==puste)
                    break;
                if(a.pola[x+1][y]==czarne)
                    a.pola[x][y]=biale;
                if(a.pola[x+1][y]==biale){
                    a.pola[x][y]=biale;
                    break;
                }
            }
        }

        if(a.czyjruch==czarne){
            a.pola[i][j]=czarne;
            x=i;
            y=j;
            while(a.pola[x-1][y+1]==biale && x>0 && y<n)
            {
                x--;
                y++;
                if(a.pola[x-1][y+1]==puste)
                    break;
                if(a.pola[x-1][y+1]==biale)
                    a.pola[x][y]=czarne;
                if(a.pola[x-1][y+1]==czarne){
                    a.pola[x][y]=czarne;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x+1][y+1]==biale && x<n && y<n)
            {
                x++;
                y++;
                if(a.pola[x+1][y+1]==puste)
                    break;
                if(a.pola[x+1][y+1]==biale)
                    a.pola[x][y]=czarne;
                if(a.pola[x+1][y+1]==czarne){
                    a.pola[x][y]=czarne;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x+1][y-1]==biale && x<n && y>0)
            {
                x++;
                y--;
                if(a.pola[x+1][y-1]==puste)
                    break;
                if(a.pola[x+1][y-1]==biale)
                    a.pola[x][y]=czarne;
                if(a.pola[x+1][y-1]==czarne){
                    a.pola[x][y]=czarne;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x-1][y-1]==biale && x>0 && y>0)
            {
                x--;
                y--;
                if(a.pola[x-1][y-1]==puste)
                    break;
                if(a.pola[x-1][y-1]==biale)
                    a.pola[x][y]=czarne;
                if(a.pola[x-1][y-1]==czarne){
                    a.pola[x][y]=czarne;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x][y+1]==biale && y<n)
            {
                y++;
                if(a.pola[x][y+1]==puste)
                    break;
                if(a.pola[x][y+1]==biale)
                    a.pola[x][y]=czarne;
                if(a.pola[x][y+1]==czarne){
                    a.pola[x][y]=czarne;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x][y-1]==biale && y>0)
            {
                y--;
                if(a.pola[x][y-1]==puste)
                    break;
                if(a.pola[x][y-1]==biale)
                    a.pola[x][y]=czarne;
                if(a.pola[x][y-1]==czarne){
                    a.pola[x][y]=czarne;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x-1][y]==biale && x>0)
            {
                x--;
                if(a.pola[x-1][y]==puste)
                    break;
                if(a.pola[x-1][y]==biale)
                    a.pola[x][y]=czarne;
                if(a.pola[x-1][y]==czarne){
                    a.pola[x][y]=czarne;
                    break;
                }
            }
            x=i;
            y=j;
            while(a.pola[x+1][y]==biale && x<n)
            {
                x++;
                if(a.pola[x+1][y]==puste)
                    break;
                if(a.pola[x+1][y]==biale)
                    a.pola[x][y]=czarne;
                if(a.pola[x+1][y]==czarne){
                    a.pola[x][y]=czarne;
                    break;
                }
            }
        }
    }
    return a;
}

#endif