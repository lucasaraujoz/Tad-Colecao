#ifndef _COLECTION_H_
#define _COLECTION_H_
typedef struct _colection Colection;
Colection *colCreate(int max_items);
int colInsert(Colection *c, void *item);
void *colRemove(Colection *c, void *key);
void *colQuery(Colection *c, void *key);
void *colGetFirst(Colection *c);
void *colGetNext(Colection *c);
int colDestroy(Colection *c);
void print(Colection *c);

#endif