#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Konstans mátrix a könyebb számoláshoz
const sum[2][12] = {
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31},
    };

//Struktura definiálása
 struct  date {
        int year;
        int month;
        int day;
    };
//
typedef struct date date;

char* writem(int month);
int countdays(date be);
date wdate(int year, int days);
int leapyear(int year);

int main()
{
    date data;
    int ok = 0;
    char c;
    //Ellenõrzött beolvasás
    do{
        ok = 1;
        printf("Kerek egy datumot!(Pl.:2000.01.31.) ");
        if (scanf("%d.%d.%d", &data.year, &data.month, &data.day) != 3 || 1 > data.year || 1 > data.month || data.month > 12 || 1 > data.day || data.day > 32 || ((data.month == 2) && (data.day > 29)))
            {
                printf("Hibas adat!\n");
                ok = 0;
            }
        if (((data.year%4 != 0) || ((data.year%400 != 0) && (data.year%100 == 0))) && ((data.month == 2) && (data.day == 29)))
            {
                printf("Hibas adat, a datum nem szokoev!\n");
                ok = 0;
            }
        while((c=getchar()) != '\n');
    }while(!ok);
    //Hónap számát szöveggé alakítás
    printf("%d. %s %d. ", data.year, writem(data.month), data.day);
    //Adott dátum melyik nap az éveben kiszámítása
    printf("%d. nap!\n", countdays(data));
    //Adott a nap és az év, kiszámoljuk a dátumon és eltároljuk egy date struktúrába
    date data2 = wdate(data.year, countdays(data));
    //Kiírjuk a kapott eredményeket
    printf("%d. nap az %d. %s %d.\n", countdays(data), data2.year, writem(data2.month), data2.day);
    return 0;
}

char* writem(int month)
{
    switch(month)
    {
        case 1: return "Januar";
        case 2: return "Februar";
        case 3: return "Marcius";
        case 4: return "Aprilis";
        case 5: return "Majus";
        case 6: return "Junius";
        case 7: return "Julius";
        case 8: return "Augusztus";
        case 9: return "Szeptember";
        case 10: return "Oktober";
        case 11: return "November";
        case 12: return "December";
    }
}

int leapyear(int year)
{
    if (year%4 == 0 && year%100 != 0 || year%400 == 0)
        return 1;
    else
        return 0;
}

int countdays(date be)
{
    int count = 0, i;
    if (!leapyear(be.year))
        for (i = 0; i < be.month; i++)
            if (be.month == i+1)
            {
                count += be.day;
                return count;
            }
            else
                count += sum[0][i];
    else
        for (i = 0; i < be.month; i++)
            if (be.month == i+1)
            {
                count += be.day;
                return count;
            }
            else
                count += sum[1][i];
}

date wdate(int year, int days)
{
    int i = 0,  count = 0;;
    date result;
    int a = leapyear(year);
    result.year = year;
    if (!leapyear(year))
        while(1)
        {
            if (sum[0][i] < days)
                days -= sum[0][i];
            else
            {
                result.month = i+1;
                result.day = days;
                return result;
            }
            i++;
        }
    else
        while (1)
        {
            if (sum[1][i] < days)
                days -= sum[1][i];
            else
            {
                result.month = i+1;
                result.day = days;
                return result;
            }
            i++;
        }
}




















