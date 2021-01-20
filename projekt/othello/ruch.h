#ifndef RUCH_H
#define RUCH_H

#include "def.h"

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