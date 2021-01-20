#ifndef OCENA_H
#define OCENA_H

#include "def.h"

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

void rezultat(int score)
{    

    if(score==100){
        printf("Biały wygrywa!\n");
        exit(100);
    }
    if(score==-100){
        printf("Czarny wygrywa!\n");
        exit(-100);
    }
    if(score==0){
        printf("Remis!\n");
        exit(0);
    }
}

#endif