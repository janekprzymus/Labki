#ifndef LOGIKA_H
#define LOGIKA_H

#include "lista_ruchow.h"

void zmiana_gracza(plansza *a){
    a->czyjruch=(a->czyjruch+1)%2;
}

listaruchow *mozliwosci(plansza *a, listaruchow *l)
{
    int i,j,x,y;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            if(a->pola[i][j]==mozliwe)
                a->pola[i][j]=puste;
        }
    if(a->czyjruch==biale){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(a->pola[i][j]==biale)
                {
                    x=i;
                    y=j;
                    while(a->pola[x-1][y]==czarne && x>0)
                    {
                        x--;
                        if(a->pola[x-1][y]==puste && x>0)
                        {
                            a->pola[x-1][y]=mozliwe;
                            break;
                        }
                        if(a->pola[x-1][y]==biale)
                            break;
                        if(a->pola[x-1][y]==mozliwe)
                        {
                            a->pola[x-1][y]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x+1][y]==czarne && x<n)
                    {
                        x++;
                        if(a->pola[x+1][y]==puste && x<n)
                        {
                            a->pola[x+1][y]=mozliwe;
                            break;
                        }
                        if(a->pola[x+1][y]==biale)
                            break;
                        if(a->pola[x+1][y]==mozliwe)
                        {
                            a->pola[x+1][y]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x][y-1]==czarne && y>0)
                    {
                        y--;
                        if(a->pola[x][y-1]==puste && y>0)
                        {
                            a->pola[x][y-1]=mozliwe;
                            break;
                        }
                        if(a->pola[x][y-1]==biale)
                            break;
                        if(a->pola[x][y-1]==mozliwe)
                        {
                            a->pola[x][y-1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x][y+1]==czarne && y<n)
                    {
                        y++;
                        if(a->pola[x][y+1]==puste && y<n)
                        {
                            a->pola[x][y+1]=mozliwe;
                            break;
                        }
                        if(a->pola[x][y+1]==biale)
                            break;
                        if(a->pola[x][y+1]==mozliwe)
                        {
                            a->pola[x][y+1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x+1][y+1]==czarne && x<n && y<n)
                    {
                        x++;
                        y++;
                        if(a->pola[x+1][y+1]==puste && x<n && y<n)
                        {
                            a->pola[x+1][y+1]=mozliwe;
                            break;
                        }
                        if(a->pola[x+1][y+1]==biale)
                            break;
                        if(a->pola[x+1][y+1]==mozliwe)
                        {
                            a->pola[x+1][y+1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x-1][y-1]==czarne && x>0 && y>0)
                    {
                        x--;
                        y--;
                        if(a->pola[x-1][y-1]==puste && x>0 && y>0)
                        {
                            a->pola[x-1][y-1]=mozliwe;
                            break;
                        }
                        if(a->pola[x-1][y-1]==biale)
                            break;
                        if(a->pola[x-1][y-1]==mozliwe)
                        {
                            a->pola[x-1][y-1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x+1][y-1]==czarne && x<n && y>0)
                    {
                        x++;
                        y--;
                        if(a->pola[x+1][y-1]==puste && x<n && y>0)
                        {
                            a->pola[x+1][y-1]=mozliwe;
                            break;
                        }
                        if(a->pola[x+1][y-1]==biale)
                            break;
                        if(a->pola[x+1][y-1]==mozliwe)
                        {
                            a->pola[x+1][y-1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x-1][y+1]==czarne && x>0 && y<n)
                    {
                        x--;
                        y++;
                        if(a->pola[x-1][y+1]==puste && x>0 && y<n)
                        {
                            a->pola[x-1][y+1]=mozliwe;
                            break;
                        }
                        if(a->pola[x-1][y+1]==biale)
                            break;
                        if(a->pola[x-1][y+1]==mozliwe)
                        {
                            a->pola[x-1][y+1]=mozliwe;
                            break;
                        }
                    }
                }

            }
    }
    if(a->czyjruch==czarne){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(a->pola[i][j]==czarne)
                {
                    x=i;
                    y=j;
                    while(a->pola[x-1][y]==biale && x>0)
                    {
                        x--;
                        if(a->pola[x-1][y]==puste && x>0)
                        {
                            a->pola[x-1][y]=mozliwe;
                            break;
                        }
                        if(a->pola[x-1][y]==czarne)
                            break;
                        if(a->pola[x-1][y]==mozliwe)
                        {
                            a->pola[x-1][y]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x+1][y]==biale && x<n)
                    {
                        x++;
                        if(a->pola[x+1][y]==puste && x<n)
                        {
                            a->pola[x+1][y]=mozliwe;
                            break;
                        }
                        if(a->pola[x+1][y]==czarne)
                            break;
                        if(a->pola[x+1][y]==mozliwe)
                        {
                            a->pola[x+1][y]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x][y-1]==biale && y>0)
                    {
                        y--;
                        if(a->pola[x][y-1]==puste && y>0)
                        {
                            a->pola[x][y-1]=mozliwe;
                            break;
                        }
                        if(a->pola[x][y-1]==czarne)
                            break;
                        if(a->pola[x][y-1]==mozliwe)
                        {
                            a->pola[x][y-1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x][y+1]==biale && y<n)
                    {
                        y++;
                        if(a->pola[x][y+1]==puste && y<n)
                        {
                            a->pola[x][y+1]=mozliwe;
                            break;
                        }
                        if(a->pola[x][y+1]==czarne)
                            break;
                        if(a->pola[x][y+1]==mozliwe)
                        {
                            a->pola[x][y+1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x+1][y+1]==biale && x<n && y<n)
                    {
                        x++;
                        y++;
                        if(a->pola[x+1][y+1]==puste && x<n && y<n)
                        {
                            a->pola[x+1][y+1]=mozliwe;
                            break;
                        }
                        if(a->pola[x+1][y+1]==czarne)
                            break;
                        if(a->pola[x+1][y+1]==mozliwe)
                        {
                            a->pola[x+1][y+1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x-1][y-1]==biale && x>0 && y>0)
                    {
                        x--;
                        y--;
                        if(a->pola[x-1][y-1]==puste && x>0 && y>0)
                        {
                            a->pola[x-1][y-1]=mozliwe;
                            break;
                        }
                        if(a->pola[x-1][y-1]==czarne)
                            break;
                        if(a->pola[x-1][y-1]==mozliwe)
                        {
                            a->pola[x-1][y-1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x+1][y-1]==biale && x<n && y>0)
                    {
                        x++;
                        y--;
                        if(a->pola[x+1][y-1]==puste && x<n && y>0)
                        {
                            a->pola[x+1][y-1]=mozliwe;
                            break;
                        }
                        if(a->pola[x+1][y-1]==czarne)
                            break;
                        if(a->pola[x+1][y-1]==mozliwe)
                        {
                            a->pola[x+1][y-1]=mozliwe;
                            break;
                        }
                    }
                    x=i;
                    y=j;
                    while(a->pola[x-1][y+1]==biale && x>0 && y<n)
                    {
                        x--;
                        y++;
                        if(a->pola[x-1][y+1]==puste && x>0 && y<n)
                        {
                            a->pola[x-1][y+1]=mozliwe;
                            break;
                        }
                        if(a->pola[x-1][y+1]==czarne)
                            break;
                        if(a->pola[x-1][y+1]==mozliwe)
                        {
                            a->pola[x-1][y+1]=mozliwe;
                            break;
                        }
                    }
                }

            }
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            if(a->pola[i][j]==mozliwe)
                l = dodaj_ruch(l, i, j);
        }
    return l;
}

#endif