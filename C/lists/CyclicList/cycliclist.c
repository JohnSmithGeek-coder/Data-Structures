#include <stdio.h>
#include <stdlib.h>
#include "cycliclist.h"

List CreateList(void)
{
    List L;
    L = (PtrToNode)malloc(sizeof(struct Node));
    if(!L){
        Error("Out of space!\n");
        return NULL;
    }
    L->Next = NULL;
    int n, i;
    scanf("%d", &n);
    if(n <= 0)
    {
        return L;
    }
    PtrToNode P, Q;
    Q = L;
    ElementType X;
    for(i = 0; i < n; i++)
    {
        P = (PtrToNode)malloc(sizeof(struct Node));
        if(!P){
            Error("Out of space! Create Failed!\n");
            return L;
        }
        scanf("%d", &X);
        P->Data = X;
        P->Next = NULL;
        Q->Next = P;
        Q = P;
    }
    P->Next = L->Next;
    return L;
}

Status IsEmpty(List L)
{
    if(!L->Next)
    {
        return TRUE;
    }
    return FALSE;
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

Position GetLast(List L)
{
    if(IsEmpty(L))
    {
        return NULL;
    }
    PtrToNode P;
    P = L->Next;
    while(P->Next != L->Next)
    {
        P = P->Next;
    }
    return P;
}

Position FindPrevious(List L, ElementType X)
{
    if(IsEmpty(L)){
        return NULL;
    }
    PtrToNode P;
    P = L->Next;
    if(P->Next->Data == X)
    {
        return P;
    }
    P = P->Next;
    while(P->Next != L->Next->Next && P->Next->Data != X)
    {
        P = P->Next;
    }
    if(P->Next == L->Next->Next)
    {
        return NULL;
    }
    return P;
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
    while(P->Data != X && P != L->Next)
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

Status DeleteFirst(List L, Position Last)
{
    PtrToNode P, Q;
    P = L->Next;
    Q = Last;
    if(P == Q)
    {
        L->Next = NULL;
        free(P);
        return OK;
    }
    Q->Next = P->Next;
    free(P);
    L->Next = Q->Next;
    return OK;
}

Status DeletebyPtr(List L, Position P)
{
    PtrToNode Q;
    if(P->Next == L->Next)
    {
        DeleteFirst(L, P);
        return OK;
    }
    Q = P->Next;
    P->Next = Q->Next;
    free(Q);
    return OK;
}

Status DeletebyIndex(List L, int index)
{
    if(IsEmpty(L))
    {
        Error("List is empty! Delete failed!\n");
        return ERROR;
    }
    if(index == 1)
    {
        PtrToNode Last;
        Last = GetLast(L);
        DeletebyPtr(L, Last);
        return OK;
    }
    PtrToNode P, Q;
    P = L->Next;
    int i = 3;
    if(index == 2)
    {
        DeletebyPtr(L, P);
    }
    P = P->Next;
    while(P != L->Next && i != index)
    {
        P = P->Next;
        i++;
    }
    if(P == L->Next){
        Error("Wrong index! Delete failed\n");
        return ERROR;
    }
    DeletebyPtr(L, P);
    return OK;
}

Status DeletebyElement(List L, ElementType X)
{
    PtrToNode P;
    P = FindPrevious(L, X);
    if(P){
        DeletebyPtr(L, P);
        return OK;
    }
    return ERROR;
}

Status InsertFirst(List L, ElementType X)
{
    Position Last;
    Last = GetLast(L);
    PtrToNode P, newNode;
    newNode = (PtrToNode)malloc(sizeof(struct Node));
    if(!newNode)
    {
        Error("Out of space! Insert failed!\n");
        return ERROR;
    }
    newNode->Data = X;
    newNode->Next = NULL;
    if(!Last){
        L->Next = newNode;
        newNode->Next = newNode;
        return OK;
    }
    P = Last->Next;
    Last->Next = newNode;
    newNode->Next = P;
    L->Next = newNode;
    return OK;
}

Status InsertbyPtr(List L, Position P, ElementType X)
{
    PtrToNode newNode, Q;
    newNode = (PtrToNode)malloc(sizeof(struct Node));
    if(!newNode)
    {
        Error("Out of space! Insert failed\n");
        return ERROR;
    }
    newNode->Data = X;
    newNode->Next = NULL;
    Q = P->Next;
    P->Next = newNode;
    newNode->Next = Q;
    return OK;
}

Status InsertbyIndex(List L, int index, ElementType X)
{
    if(index == 1)
    {
        InsertFirst(L, X);
        return OK;
    }
    PtrToNode P, Q;
    P = L->Next;
    if(index == 2){
        InsertbyPtr(L, P, X);
        return OK;
    }
    P = P->Next;
    int i = 3;
    while(i < index && P->Next != L->Next)
    {
        P = P->Next;
        i++;
    }
    if(P->Next == L->Next)
    {
        Error("Wrong index! Insert failed\n");
        return ERROR;
    }
    InsertbyPtr(L, P, X);
    return OK;
}

Status ListAppend(List L, ElementType X)
{
    if(IsEmpty(L))
    {
        InsertFirst(L, X);
        return OK;
    }
    Position P;
    P = GetLast(L);
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
    PtrToNode P;
    P = L->Next;
    printf("%d ", P->Data);
    P = P->Next;
    while(P != L->Next)
    {
        printf("%d ", P->Data);
        P = P->Next;
    }
    printf("\n");
}