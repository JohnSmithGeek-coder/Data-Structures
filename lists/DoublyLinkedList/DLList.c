#include <stdio.h>
#include <stdlib.h>
#include "DLList.h"

List CreateList(void)
{
    List L;
    L = (PtrToNode)malloc(sizeof(struct Node));
    L->Next = NULL;
    L->Prev = NULL;
    int n;
    scanf("%d", &n);
    int X, i;
    PtrToNode P, Q;
    Q = L;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &X);
        P = (PtrToNode)malloc(sizeof(struct Node));
        P->Data = X;
        P->Next = NULL;
        P->Prev = Q;
        Q->Next = P;
        Q = P;
    }
    return L;
}

Status IsEmpty(List L)
{
    if(L->Next == NULL)
    {
        return TRUE;
    }
    return FALSE;
}

Status MakeEmpyt(List L)
{
    PtrToNode P, Q;
    P = L->Next;
    L->Next = NULL;
    while(P)
    {
        Q = P->Next;
        free(P);
        P = Q;
    }
    return OK;
}

int GetListLength(List L)
{
    int length = 0;
    PtrToNode P;
    P = L->Next;
    while(P)
    {
        length++;
        P = P->Next;
    }
    return length;
}

Position GetLast(List L)
{
    PtrToNode P;
    P = L->Next;
    while(P->Next)
    {
        P = P->Next;
    }
    return P;
}

Position FindElement(List L, ElementType X)
{
    PtrToNode P;
    P = L->Next;
    while(P && P->Data != X)
    {
        P = P->Next;
    }
    if(!P)
    {
        return NULL;
    }
    return P;
}

Status LocateElem(List L, ElementType X)
{
    if(FindElement(L, X))
    {
        return TRUE;
    }
    return FALSE;
}

Status DeletebyPtr(List L, Position P)
{
    PtrToNode Q;
    if(!P->Next)
    {
        Q = P->Prev;
        Q->Next = NULL;
        free(P);
        return OK;
    }
    Q = P->Prev;
    Q->Next = P->Next;
    P->Next->Prev = Q;
    free(P);
    return OK;
}

Status DeletebyElement(List L, ElementType X)
{
    Position P;
    P = FindElement(L, X);
    if(!P){
        printf("No such element! Delete failed!\n");
        return ERROR;
    }
    DeletebyPtr(L, P);
    return OK;
}

Status DeletebyIndex(List L, int index)
{
    if(index <= 0){
        printf("Wrong index! Delete failed!\n");
        return ERROR;
    }
    int i = 1;
    PtrToNode P;
    P = L->Next;
    while(i < index && P)
    {
        P = P->Next;
        i++;
    }
    if(!P)
    {
        Error("Wrong index! Delete Failed!\n");
        return ERROR;
    }
    DeletebyPtr(L, P);
    return OK;
}

Status InsertbyPtr(List L, Position P, ElementType X)
{
    PtrToNode newNode;
    newNode = (PtrToNode)malloc(sizeof(struct Node));
    newNode->Data = X;
    newNode->Next = NULL;
    newNode->Prev = NULL;
    if(!P->Next)
    {
        newNode->Next = NULL;
        newNode->Prev = P;
        P->Next = newNode;
        return OK;
    }
    newNode->Next = P->Next;
    P->Next = newNode;
    newNode->Prev = P;
    newNode->Next->Prev = newNode;
    return OK;
}

Status InsertbyIndex(List L, int index, ElementType X)
{
    if(index <= 0)
    {
        Error("Wrong Index! Insert Failed!\n");
        return ERROR;
    }    
    PtrToNode P;
    P = L;
    int i = 1;
    while(i < index && P)
    {
        P = P->Next;
        i++;
    }
    if(!P)
    {
        Error("Wrong Index! Insert Failed!\n");
        return ERROR;
    }
    InsertbyPtr(L, P, X);
    return OK;
}

Status DestroyList(List L)
{
    MakeEmpyt(L);
    free(L);
    return OK;
}

void PrintList(List L)
{
    if(IsEmpty(L))
    {
        printf("List is empty!\n");
        return;
    }
    PtrToNode P;
    P = L->Next;
    while(P)
    {
        printf("%d ", P->Data);
        P = P->Next;
    }
    printf("\n");
}