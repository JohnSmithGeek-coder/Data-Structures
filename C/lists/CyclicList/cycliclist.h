#ifndef _CYCLICLIST_H_
#define _CYCLICLIST_H_

#define Error printf
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int ElementType;
typedef int Status;

struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    ElementType Data;
    PtrToNode Next;
};

List CreateList(void);
Status IsEmpty(List L);
int GetListLength(List L);
Position GetLast(List L);
Position FindPrevious(List L, ElementType X);
Position FindElement(List L, ElementType X);
Status LocateElem(List L, ElementType X);
Status DeleteFirst(List L, Position Last);
Status DeletebyPtr(List L, Position P);
Status DeletebyIndex(List L, int index);
Status DeletebyElement(List L, ElementType X);
Status InsertFirst(List L, ElementType X);
Status InsertbyPtr(List L, Position P, ElementType X);
Status InsertbyIndex(List L, int index, ElementType X);
Status ListAppend(List L, ElementType X);
void PrintList(List L);

#endif