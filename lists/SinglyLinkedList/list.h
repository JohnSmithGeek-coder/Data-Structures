#ifndef _LIST_H_
#define _List_H_

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
int GetListLength(List L);
ElementType GetElement(List L, int i);
Status IsEmpty(List L);
Status MakeEmpty(List L);
Position FindElement(List L, ElementType X);
Status LocateElem(List L, ElementType X);
Position FindPrevious(List L, ElementType X);
Position FindNthNodefromEnd(List L, int N);
Status InsertbyPtr(List L, Position P, ElementType X);
Status InsertbyIndex(List L, int index, ElementType X);
Status DeletebyPtr(List L, Position P);
Status DeletebyElement(List L, ElementType X);
Status DeletebyIndex(List L, int index);
List MergeList(List La, List Lb);
Status ReverseList(List L);
Status DestroyList(List L);
void PrintList(List L);

#endif