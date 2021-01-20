#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct macierz
{
    int wiersze, kolumny;
    float *elementy; 
};

struct macierz utworz(int wiersze, int kolumny)
{
    struct macierz m = {wiersze, kolumny, calloc(wiersze*kolumny, sizeof(float))};

    return m;
}

struct macierz zapisz(struct macierz m, char nazwa[])
{
    FILE *fout = fopen(nazwa, "w");
    int i, j, n=0;

    fprintf(fout, "%d\n%d\n", m.wiersze, m.kolumny);
    for(i=0; i<m.wiersze; i++)
    {
        for(j=0; j<m.kolumny; j++){
            fprintf(fout, "%5.1f", m.elementy[n]);
            n++;
        }
        fprintf(fout, "\n");
    }
    fclose(fout);
}

struct macierz wczytaj(char nazwa[])
{
    FILE *fin = fopen(nazwa, "r");
    int i, j, n=0;
    struct macierz *m;
    fscanf(fin, "%d", &m->wiersze);
    fscanf(fin, "%d", &m->kolumny);

    for(i=0; i < m->wiersze; i++)
    {
        for(j=0; j < m->kolumny; j++)
        {
            fscanf(fin, "%f", &m->elementy[n]);
            n++;
        }
    }
    return *m;
}

void wypisz(struct macierz m)
{
    int i, j, n=0;

    for(i=0; i<m.wiersze; i++)
    {
        printf("[");
        for(j=0; j<m.kolumny; j++)
        {
            printf("%6.3f ", m.elementy[n]);
            n++;
        }
        printf(" ]\n");
    }
}

void zniszcz(struct macierz m)
{
    free(m.elementy);
}

struct macierz minorek(struct macierz m, int wiersz, int kolumna)
{
    struct macierz n = utworz(m.wiersze-1, m.kolumny-1);
    int j=0;
    for(int i=0; i<m.wiersze*m.kolumny; i++) //jak skończy się zapełnianie macierzy n
    {
        if(j>=n.kolumny*n.wiersze)
            break;
        if(!(i/m.kolumny == wiersz || i%m.kolumny == kolumna)){ //sprawdza czy dany element[i] nie jest w podanym wierszu lub kolumnie
            n.elementy[j] = m.elementy[i]; //jezeli nie jest to wpisuje go do macierzy n
            j++;
        }
    }
    return n;
}

float det(struct macierz m)
{
    int i;
    float w=0;

    if(m.kolumny!=m.wiersze)
    {
        printf("Nie mozna obliczyc wyznacznika, macierz nie jest kwadratowa.\n");
        exit(-2);
    }
    else if(m.wiersze==1)
    {
        w+=m.elementy[0];
        return w;
    }
    else
    {   
        
        for(i=0; i<m.wiersze; i++)
        {
            struct macierz n = minorek(m,0,i);
            w+=pow((-1),i)*m.elementy[i]*det(n);
            zniszcz(n);
        }
        return w;
    }
}

struct macierz dopelnienia(struct macierz a){
    struct macierz b = utworz(a.wiersze, a.kolumny);
    for(int i=0; i<b.wiersze; i++){
        for(int j=0; j<b.kolumny; j++){
            b.elementy[i*b.kolumny+j]=pow((-1),(i*b.kolumny+j))*det(minorek(a,i,j));
        }
    }
        
    return b;
}

struct macierz odwrotnosc(struct macierz a, float det){
    struct macierz b=utworz(a.wiersze, a.kolumny);
    int i,j;
    for(i=0; i<a.wiersze; i++){
        for(j=0; j<a.kolumny; j++){
            b.elementy[j*b.kolumny+i]=a.elementy[i*a.kolumny+j];
        }
    }
    zniszcz(a);
    for(i=0; i<(b.wiersze*b.kolumny); i++){
        b.elementy[i]=b.elementy[i]/det;
    }
    return b;
}

void main(void)
{
    // void *ptr = calloc(1000, sizeof(int));
    struct macierz m=utworz(5, 5);
    wypisz(m);
    zapisz(m, "macierz.txt");
    zniszcz(m);

    struct macierz n;
    n=wczytaj("macierz2.txt");
    printf("\n");
    wypisz(n);
    printf("Wyznacznik macierzy: %f\n", det(n));
    printf("Macierz dopelnien:\n");
    wypisz(dopelnienia(n));
    printf("Odwrotnosc macierzy:\n");
    wypisz(odwrotnosc(dopelnienia(n), det(n)));
    zniszcz(n);
}