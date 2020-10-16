#include <stdio.h>
#include <stdlib.h>
#include "DCLList.h"

List CreateList(void)
{
    List L;
    L = (PtrToNode)malloc(sizeof(struct Node));
    if(!L){
        Error("Out of space!!!\n");
    }
    L->Next = NULL;
    L->Prev = NULL;
    int n;
    scanf("%d", &n);
    int i, X;
    PtrToNode P, Q;
    Q = L;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &X);
        P = (PtrToNode)malloc(sizeof(struct Node));
        if(!L){
            Error("Out of space!!!\n");
        }
        P->Data = X;
        P->Next = NULL;
        Q->Next = P;
        P->Prev = Q;
        Q = P;
    }
    P->Next = L->Next;
    L->Next->Prev = P;
    return L;
}

Status IsEmpty(List L)
{
    if(!L->Next)
    {
        return TRUE;
    }else{
        return FALSE;
    }
}

Status MakeEmpyt(List L)
{
    if(IsEmpty(L)){
        return OK;
    }
    PtrToNode P, Q;
    P = L->Next;
    Q = P->Next;
    free(P);
    P = Q;
    while(P != L->Next)
    {
        Q = P->Next;
        free(P);
        P = Q;
    }
    L->Next = NULL;
    return OK;
}

int GetListLength(List L)
{
    if(IsEmpty(L))
    {
        return 0;
    }
    PtrToNode P;
    P = L->Next;
    int length = 1;
    P = P->Next;
    while(P != L->Next)
    {
        length++;
        P = P->Next;
    }
    return length;
}

Position FindElement(List L, ElementType X)
{
    if(IsEmpty(L))
    {
        return NULL;
    }
    PtrToNode P;
    P = L->Next;
    if(P->Data == X)
    {
        return P;
    }
    P = P->Next;
    while(P != L->Next && P->Data != X)
    {
        P = P->Next;
    }
    if(P == L->Next)
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

Status DeleteFirst(List L)
{
    if(IsEmpty(L))
    {
        return ERROR;
    }
    PtrToNode P, Q;
    P = L->Next;
    Q = P->Prev;
    if(P->Next == L->Next)
    {
        L->Next = NULL;
        free(P);
        return OK;
    }
    Q->Next = P->Next;
    P->Next->Prev = Q;
    free(P);
    L->Next = Q->Next;
    return OK;
}

Status DeletebyPtr(List L, Position P)
{
    if(P == L->Next)
    {
        DeleteFirst(L);
        return OK;
    }
    PtrToNode Q;
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
    if(P)
    {
        DeletebyPtr(L, P);
        return OK;
    }
    Error("No such element! Delete failed!\n");
    return ERROR;
}

Status DeletebyIndex(List L, int index)
{
    if(index <= 0)
    {
        Error("Wrong Index! Delete Failed!\n");
        return ERROR;
    }
    if(IsEmpty(L))
    {
        Error("List is empty! Delete Failed!\n");
        return ERROR;
    }
    int i = 1;
    PtrToNode P, Q;
    P = L->Next;
    if(i == index)
    {
        DeletebyPtr(L, P);
        return OK;
    }
    P = P->Next;
    i++;
    while(P != L->Next && i != index)
    {
        P = P->Next;
        i++;
    }
    if(P == L->Next)
    {
        Error("Wrong Index! Delete Failed!\n");
        return ERROR;
    }
    DeletebyPtr(L, P);
    return OK;
}

Status InsertFirst(List L, ElementType X)
{
    PtrToNode newNode, P;
    newNode = (PtrToNode)malloc(sizeof(struct Node));
    if(!newNode)
    {
        Error("Out of space!!!\n");
        return ERROR;
    }
    newNode->Data = X;
    newNode->Next = NULL;
    newNode->Prev = NULL;
    if(IsEmpty(L))
    {
        L->Next = newNode;
        newNode->Next = newNode;
        newNode->Prev = newNode;
        return OK;
    }
    P = L->Next;
    P->Prev->Next = newNode;
    newNode->Prev = P->Prev;
    newNode->Next = P;
    P->Prev = newNode;
    L->Next = newNode;
    return OK;
}

Status InsertbyPtr(List L, Position P, ElementType X)
{
    PtrToNode newNode, Q;
    newNode = (PtrToNode)malloc(sizeof(struct Node));
    if(!newNode)
    {
        Error("Out of space!!!\n");
        return ERROR;
    }
    newNode->Data = X;
    Q = P->Next;
    P->Next = newNode;
    newNode->Next = Q;
    newNode->Prev = P;
    Q->Prev = newNode;
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
    if(index == 1)
    {
        InsertFirst(L, X);
        return OK;
    }
    P = P->Next;
    if(index == 2)
    {
        InsertbyPtr(L, P, X);
        return OK;
    }
    P = P->Next;
    int i = 3;
    while(index != i && P != L->Next)
    {
        P = P->Next;
        i++;
    }
    if(P == L->Next)
    {
        Error("Wrong Index! Insert Failed!\n");
        return ERROR;
    }
    InsertbyPtr(L, P, X);
    return OK;
}

void PrintList(List L)
{
    if(IsEmpty(L))
    {
        printf("List is empty!\n");
        return;
    }
    printf("OUT:\n");
    PtrToNode P;
    P = L->Next;
    printf("    %d ", P->Data);
    P = P->Prev;
    while(P != L->Next)
    {
        printf("%d ", P->Data);
        P = P->Prev;
    }
    printf("\n");
    printf("    %d ", P->Data);
    P = P->Next;
    while(P != L->Next)
    {
        printf("%d ", P->Data);
        P = P->Next;
    }
    printf("\n");
}