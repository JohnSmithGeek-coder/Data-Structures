#ifndef _LIST_H_
#define _LIST_H_

#define LIST_INIT_SIZE 101
#define LISTINCREMENT 1
#define OK 1
#define ERROR 0
#define OVERFLOW 0
#define TRUE 1
#define FALSE 0

typedef int ElementType;
typedef int Status;

/*Struct for list*/
typedef struct{
    ElementType *elem;
    int length;
    int listsize;
}List;

Status InitList(List *L);
int FindElement(List *L, ElementType e);
Status LocateElem(List *L, ElementType e);
Status IsListEmpty(List *L);
Status getListLength(List *L);
Status ListInsert(List *L, int index, ElementType e);
Status ListElemDelete(List *L, ElementType e);
Status ListPositionDelete(List *L, int index);
void PrintList(List *L);

#endif