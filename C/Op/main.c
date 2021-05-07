#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c[20];
    FILE* fp = fopen("torma.txt", "w+");
    fprintf(fp, "Torma_Antal\n", "%s");
    fprintf(fp, "Mernokinformatika\n", "%s");
    fprintf(fp, "YK11Q1\n", "%s");
    fseek(fp, 0, SEEK_SET);
    while (fscanf(fp, "%s",c) != EOF){
        printf("%s\n", c);
    }
    fclose(fp);
    return 0;
}
