#include <stdio.h>
#include <stdlib.h>

double alakit(double fok);
double *ktomb(double* c, double* k);
void  hatar();
double ingas(double* k);
void file(double* k);
void atlag(double* c);

int main()
{
    double c[7] = {10.1, 13.2, 11.0, 12.3, 14.0, 13.5, 13.3};
    double k[7];
    ktomb(c, k);
    hatar(k);
    ingas(k);
    file(k);
    atlag(c);
    return 0;
}
double alakit(double fok)
{
    return fok+273.15;
}

double *ktomb(double* c, double* k)
{
   for(int i = 0; i < 7; i++)
    {
        k[i] = alakit(c[i]);
    }
    return k;
}
void hatar(double *k)
{
    char c;
    int ok;
    double min, max;
    do {
        ok = 1;
        printf("Kerek egy intervallumot: ");
        if ((scanf("%lf %lf", &min, &max) != 2) || (max < min))
        {
            printf("Hibas adat!\n");
            ok = 0;
        }
        while((c=getchar()) != '\n');
    }while(!ok);
    for(int i = 0; i < 7; i++)
    {
        if(k[i]>min && k[i]<max)
        {
            printf("%.2lf\n", k[i]);
        }
    }
}
double ingas(double* k)
{
    double min = k[0], max = k[0];
    for(int i = 1; i<7; i++)
    {
        if (k[i] > max) max = k[i];
        if (k[i] < min) min = k[i];
    }
    printf("%.2lf\n", max-min);
    return max-min;
}
void file(double* k)
{
    FILE *fp;
    fp=fopen("vizsga.txt", "at");
    for(int i = 0; i < 7; i++)
    {
        fprintf(fp, "%.2lf K\n", k[i]);
    }
    fclose(fp);
}
void atlag(double* c)
{
    double atlag = 0;
    for(int i = 0; i < 7;i++)
    {
        atlag += c[i];
    }
    atlag /= 7;
    for(int i = 0; i< 7; i++)
    {
        if(c[i]>atlag)
            printf("%d\t", i);
    }
}
