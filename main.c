#include <stdio.h>
#include "colection.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _aluno
{
    char name[30];
    int matr;
    float nota;
} Aluno;

void menu()
{
    printf("1 - Criar colection\n");
    printf("2 - Inserir na colection\n");
    printf("3 - Listar colection\n");
    printf("4 - Buscar na colection\n");
    printf("5 - Remover da colection\n");
    printf("6 - Limpar a colection\n");
}

int cmpmatr(void *a, void *b)
{
    int *matr = (int *)a;
    Aluno *al = (Aluno *)b;

    if (al->matr == *matr)
    {
        return true;
    }
    return false;
}

int main(void)
{
    Colection *col;
    Aluno *a;
    int tam, z, key;
    char opc;
    while (opc != '7')
    {
        system("CLS");
        menu();
        printf("escolha uma op: ");
        scanf("%c", &opc);
        switch (opc)
        {
        case '1':
            system("CLS");
            printf("opc 1\n");
            printf("Tamanho da colecao: ");
            scanf("%d", &tam);
            col = colCreate(tam); // col = e2004
            system("PAUSE");
            break;
        case '2':
            system("CLS");
            printf("opc 2\n");
            if (col != NULL)
            {
                for (int i = 0; i < 3; i++)
                {
                    //sobresce pq cria outra estrutura e salva o endereço em a;
                    a = (Aluno *)malloc(sizeof(Aluno) * 1); //cria estrutura e salva endereço em "a", dps sobrescreve
                    if (a != NULL)
                    {
                        printf("Nome/Matricula/Nota: ");
                        scanf("%s %d %f", (a->name), &(a->matr), &(a->nota));
                        colInsert(col, (void *)a); //disfarço Aluno como void pra collection
                    }   
                }
            }
            system("PAUSE");
            break;
        case '3':
            system("CLS");
            printf("opc 3\n");
            if (col != NULL)
            {
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
            system("PAUSE");
            break;
        case '4':
            system("CLS");
            printf("opc 4\n");
            printf("Entre com a matricula: ");
            scanf("%d", &key);
            a = (Aluno *)colQuery(col, (void *)&key, cmpmatr);
            if (a != NULL)
            {
                printf("Matricula %d Encontrada:\n", a->matr);
                printf("Nome.....: %s\n", a->name);
                printf("Nota.....: %.3f", a->nota);
            }
            else{
                printf("Matricula nao encontrada");
            }
            system("PAUSE");
            break;
        case '6':
            system("CLS");
            printf("ola");
            colClear(col);
            system("PAUSE");
            break;
        case '5':
            system("CLS");
            printf("opc 5\n");
            printf("Entre com a matricula: ");
            scanf("%d", &key);
            a = (Aluno *)colRemove(col, (void *)&key, cmpmatr);
            if (a != NULL)
            {
                printf("%s -> removido", a->name);
            }
            system("PAUSE");
            break;
        }
    }
    colDestroy(col);
    printf("Fim do programa");
    return 0;
}