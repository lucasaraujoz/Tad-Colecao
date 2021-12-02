#include <stdio.h>
#include "colection.h"
#include <stdlib.h>
#include <string.h>

typedef struct _aluno
{
    char name[30];
    int matr;
    float nota;
} Aluno;

int main(void)
{
    Colection *col;
    Aluno *a;
    col = colCreate(10);
    if (col != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            //sobresce pq cria outra estrutura e salva o endereço em a;
            a = (Aluno *)malloc(sizeof(Aluno) * 1); //cria estrutura e salva endereço em "a", dps sobrescreve
            if (a != NULL)
            {
                printf("Nome/Matricula/Nota: ");
                scanf("%s %d %f", &(a->name), &(a->matr), &(a->nota));
                colInsert(col, (void *)a); //disfarço Aluno como void pra collection
            }
        }
        a = (Aluno *)colGetFirst(col); //retorno primeira coisa de col, so que reforço aqui// desencapo essa
        //coloco cast de aluno, pq da col ele vem como void
        int z = 0;
        while (a != NULL)
        {
            printf("%d %s %d %.2f\n", z, a->name, a->matr, a->nota);
            a = (Aluno *)colGetNext(col);
            z++;
        }
    }
    colDestroy(col);
    return 0;
}