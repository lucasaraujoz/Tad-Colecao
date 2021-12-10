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
    printf("7 - Sair");
}

int cmpmatr(void *a, void *b) //(key, elementoColeção)
{
    int *matr = (int *)a;
    Aluno *al = (Aluno *)b; //quando acesso o array da colection, ela retorna um void* que é o *b => faço cast pra Aluno, acesso entao desse Aluno a matricula e verifico se == key

    if (al->matr == *matr) //*matr acessa valor do ponteiro matr que é o proprio valor da key
    {
        return true;
    }
    return false;
}

int main(void)
{
    Colection *col = NULL;
    Aluno *a;
    int tam, z, key;
    char opc;
    while (opc != '7')
    {
        system("CLS");
        menu();
        printf("Escolha uma opcao: ");
        scanf("%c", &opc);
        switch (opc)
        {
        case '1':
            system("CLS");
            if (col == NULL)
            {
                printf("Tamanho da colecao: \n");
                scanf("%d", &tam);
                col = colCreate(tam); // col = e2004
                printf("Colecao criada!\n");
            }
            else
            {
                printf("Colecao ja foi criada\n");
            }
            system("PAUSE");
            break;
        case '2':
            system("CLS");
            if (col != NULL)
            {
                for (int i = 0; i < 3; i++)
                {
                    //sobresce pq cria outra estrutura e salva o endereço em a;
                    a = (Aluno *)malloc(sizeof(Aluno) * 1); //cria estrutura e salva endereço em "a", dps sobrescreve
                    if (a != NULL)
                    {
                        printf("Inserir novo aluno:\n");
                        printf("Nome: ");
                        scanf("%s", a->name);
                        printf("Matricula: ");
                        scanf("%d", &(a->matr));
                        printf("Nota: ");
                        scanf("%f", &(a->nota));
                        colInsert(col, (void *)a); //disfarço Aluno como void pra collection
                    }
                }
            }
            else
            {
                printf("Colecao n existe");
            }
            system("PAUSE");
            break;
        case '3':
            system("CLS");
            a = (Aluno *)colGetFirst(col); //retorno primeira coisa de col, so que reforço aqui// desencapo essa
            //coloco cast de aluno, pq da col ele vem como void
            int z = 0;
            if (a == NULL)
            {
                printf("Colecao n existe");
            }
            while (a != NULL)
            {
                printf("---\n");
                printf("Matricula: %d\nNome.....: %s\nNota.....: %.2f\n", a->matr, a->name, a->nota);
                a = (Aluno *)colGetNext(col);
                z++;
            }
            system("PAUSE");
            break;
        case '4':
            system("CLS");
            printf("Entre com a matricula: ");
            scanf("%d", &key);
            a = (Aluno *)colQuery(col, (void *)&key, cmpmatr);
            if (a != NULL)
            {
                printf("Matricula %d Encontrada:\n", a->matr);
                printf("Nome.....: %s\n", a->name);
                printf("Nota.....: %.2f\n", a->nota);
            }
            else
            {
                printf("Matricula nao encontrada\n");
            }
            system("PAUSE");
            break;
        case '5':
            system("CLS");
            printf("Entre com a matricula: ");
            scanf("%d", &key);
            a = (Aluno *)colRemove(col, (void *)&key, cmpmatr);
            if (a != NULL)
            {
                printf("%s -> removido\n", a->name);
            }
            system("PAUSE");
            break;
        case '6':
            system("CLS");
            colClear(col);
            printf("Colecao limpa\n");
            system("PAUSE");
            break;
        }
    }
    colDestroy(col);
    printf("Fim do programa");
    return 0;
}