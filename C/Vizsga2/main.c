#include <stdio.h>
#include <stdlib.h>

const int max = 5;
void kiir(char *nev[], int *pont);
void rendez(char *nev[], int *pont);
void helyezes(int hely, char *nev[], int *pont);
int be();
void holt(int *pont);

int main()
{

    char *nev[] = {"CodeFighters", "VIP", "BitCoins", "4Byte", "ByterTeam"};
    int pont[] = {88,63,75,63,87}, *szam;
    kiir(nev, pont);
    rendez(nev, pont);
    helyezes(be(),nev, pont);
    holt(pont);
    return 0;
}

void kiir(char *nev[], int *pont)
{
    for(int i = 0; i < max; i++)
    {
        printf("%s: %d\n", nev[i], pont[i]);
    }
}

void rendez(char *nev[], int *pont)
{
    int p;
    char *n;
    for(int i = 0; i < max; i++)
    {
        for(int j = i+1; j < max; j++)
        {
            if(pont[j] > pont[i])
            {
                p = pont[i]; n = nev[i];
                pont[i] = pont[j]; nev[i] = nev[j];
                pont[j] = p; nev[j] = n;
            }
        }
    }
    FILE *fp;
    fp = fopen("vizsga2.txt", "wt");
    for(int i = 0; i < max; i++)
    {
        fprintf(fp, "%s: %d\n", nev[i], pont[i]);
    }
    fclose(fp);
}

void helyezes(int hely, char *nev[], int *pont)
{
    printf("%s: %d\n", nev[hely-1], pont[hely-1]);
}

int be()
{
    int a, ok;
    char c;
    do{
        ok = 0;
        printf("Kerek egy szamot: ");
        if (scanf("%d", &a) != 1 || a > 5 || a < 1)
        {
            printf("Hibas adat\n");
            ok = 1;
            while((c = getchar()) != '\n');
        }
    }while(ok);
    return a;
}

void holt(int *pont)
{
    int volt;
    for(int i = 0; i < max-1; i++)
    {
        for(int j = i+1; j < max; j++)
        {
            if(pont[i] == pont[j])
            {
                printf("Van holt verseny a %d. helyen\n", i+1);
                volt = 1;
                break;
            }
        }
    }
    if(!volt)
    {
        printf("Nem volt egyezes");
    }
}















