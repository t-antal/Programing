#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void feltolt(double t[]);
void kiir(double t[]);
void legkisebb(double t[]);
void range(int* rangemin, int* rangemax);
double rangeav(double t[], int rangemin, int rangemax);

int main()
{
    double tomeg[10];
    int rangemin = 0, rangemax = 0;
    srand(time(0));
    feltolt(tomeg);
    kiir(tomeg);
    legkisebb(tomeg);
    range(&rangemin, &rangemax);
    printf("A tartomany atlaga: %.2f\n\n",rangeav(tomeg, rangemin, rangemax));
    return 0;
}


void feltolt(double t[])
{
    printf("1. feladat!\n");
    double value;
    for(int i = 0; i < 10; i++)
    {
        value = rand() / (double)RAND_MAX;
        value = 95 + value * 10;
        t[i] = round(value * 100) / 100;
    }
    printf("Feltoltve!\n");
}

void kiir(double t[])
{
    printf("\n2. feladat!\n");
    for (int i = 0; i < 10; i++)
        printf("%.2f\t", t[i]);
    printf("\n");
}

void legkisebb(double t[])
{
    printf("\n3. feladat!\n");
    int i, van = 0, min;
    for(i = 0; i<10; i++)
        if(t[i]>99)
        {
            van = 1, min = i;
            break;
        }
    if(van)
    {
        for(i = min+1; i<10; i++)
                if((t[min] > t[i]) && (t[i]>100))
                    min = i;
        printf("A 100 grammot meghalado ertekek kozul a legkisebb: %0.2f\n", t[min]);
    }
    else
        printf("Nincs 100 grammot meghalado ertek!\n");
}

void range(int* rangemin, int* rangemax)
{
    printf("\n4. feladat!\n");
    char c;
    int ok;
    do{
            ok = 1;
            printf("Kerek egy tartomanyt(pl.: 95-100): ");
            if (scanf("%d-%d", rangemin, rangemax) != 2)
            {
                printf("Hibas adat!\n");
                ok = 0;
                continue;
            }
            if ((*rangemin > *rangemax) || (*rangemin < 95) || (*rangemax > 105) || (*rangemax == *rangemin))
            {
                printf("Hibas adat!\n");
                ok = 0;
            }
            while ((c=getchar() != '\n'));
        }while(!ok);
}

double rangeav(double t[], int min, int max)
{
    printf("\n5. feladat!\n");
    int i, count = 0;
    double average = 0;
    for(i = 0; i < 10; i++)
        if ((t[i] > min) && (t[i] < max))
        {
            average += t[i];
            count++;
        }
    return average/count;
}
