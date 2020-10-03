#ifndef _DLLIST_H_
#define _DLLIST_H_

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
    PtrToNode Prev;
    PtrToNode Next;
};

List CreateList(void);
Status IsEmpty(List L);
Status MakeEmpyt(List L);
int GetListLength(List L);
Position GetLast(List L);
Position FindElement(List L, ElementType X);
Status LocateElem(List L, ElementType X);
Status DeleteFirst(List L);
Status DeletebyPtr(List L, Position P);
Status DeletebyElement(List L, ElementType X);
Status DeletebyIndex(List L, int index);
Status InsertFirst(List L, ElementType X);
Status InsertbyPtr(List L, Position P, ElementType X);
Status InsertbyIndex(List L, int index, ElementType X);
Status DestroyList(List L);
void PrintList(List L);

#endif