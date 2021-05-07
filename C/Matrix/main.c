#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void feltolt (int s, int o, int *m);
int* transz(int s, int o, int* m);

int main()
{
    int s, o, ok, i, j;
    char c;
    do{
        ok = 1;
        printf("Kerem a matrix meretet!(Pl.: 5,5): ");
        if (scanf("%d,%d", &s, &o) != 2 || s < 1 || o < 1)
        {
            ok = 0;
            printf("Hibas adat!\n");
        }
       while((c = getchar()) != '\n');
    }
    while(!ok);
    int* matrix = (int*) malloc(s*o*sizeof(int));
    if (matrix == 0)
        {
            printf("Nincs eleg memoria");
            exit(-1);
        }
    feltolt(s, o, matrix);
    // Mátrix kiírása
    for (i = 0; i < s; i++)
    {
        for (j = 0; j < o; j++)
            printf(" %d\t\t",matrix[i*o+j]);
        printf("\n");
    }
    int* tmatrix = transz(s, o, matrix);
    // Transzponált mátrix kiírásar
    printf("\n");
    for (i = 0; i < o; i++)
    {
        for (j = 0; j < s; j++)
            printf(" %d\t\t",tmatrix[i*s+j]);
        printf("\n");
    }
    free(matrix);
    free(tmatrix);
    printf("\n");
    return 0;
}

void feltolt(int s, int o, int *m)
{
    //matrix feltöltése 1-10 közötti egész számokkal
    int i, j;
    srand(time(0));
    for (i = 0; i < s; i++)
        for (j = 0; j < o; j++)
            m[i*o+j] = rand()%10+1;
}

int* transz(int s, int o, int* m)
{
    //sorok és oszlopok cseréje, címszerinti paraméterátadás
    int i, j;
    int* tmatrix = (int*)malloc(s*o*sizeof (int));
    if (tmatrix == 0)
        {
            printf("Nincs eleg memoria");
            exit(-1);
        }
    for (j = 0; j < o; j++)
        for (i = 0; i < s; i++)
            tmatrix[j*s+i] = m[i*o+j];
    return tmatrix;
}
