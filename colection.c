// #ifndef _COLECTION_H
// #define _COLECTION_H
#include "colection.h"
#include <stdlib.h>
#include <stdbool.h>

struct _colection
{
    int size;
    int capacity;
    int cur;
    void **item; // void item[0] = {e101, e102}
};

Colection *colCreate(int n)
{
    Colection *c;
    if (n > 0)
    {
        c = (Colection *)malloc(sizeof(Colection));
        if (c != NULL)
        {
            c->item = (void **)malloc(sizeof(void *) * n); //alocação do vetor void*
            if (c->item != NULL)
            {
                c->size = 0;
                c->capacity = n;
                return c;
            }
            free(c); //caso n conseguisse alcoar
        }
    }
    return NULL;
}

int colDestroy(Colection *c)
{
    if (c != NULL)
    {
        if (c->size == 0)
        {
            free(c->item); //limpa o vetor
            free(c);
            return true;
        }
    }
    return false;
}

int colInsert(Colection *c, void *item)
{
    if (c != NULL)
    {
        if (c->size < c->capacity)
        {
            c->item[c->size] = item;
            c->size++;
            return true;
        }
    }
    return false;
}

void *colGetFirst(Colection *c)
{
    if (c != NULL)
    {
        if (c->size > 0)
        {
            c->cur = 0;
            return c->item[c->cur];
        }
    }
    return NULL;
}

void *colGetNext(Colection *c)
{
    if (c != NULL)
    {
        c->cur++;
        if (c->cur < c->size)
        {
            return c->item[c->cur];
        }
    }
    return NULL;
}



// void print(const Colection *c){
//     if(c!=NULL){
//         a = (Aluno *)colGetFirst(col); //retorno primeira coisa de col, so que reforço aqui// desencapo essa
//         while (a != NULL)
//         {
//             printf("%d %d\n", a->matr, a->nota);
//             a = (Aluno *)colGetNext(col);
//         }
//     }
// }

// #endif