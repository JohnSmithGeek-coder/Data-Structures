#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List CreateList(void)
{
    int n, i;
    scanf("%d", &n);
    List L;
    L = (PtrToNode)malloc(sizeof(struct Node));
    L->Next = NULL;
    PtrToNode P, Q;
    Q = L;
    int X;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &X);
        P = (PtrToNode)malloc(sizeof(struct Node));
        if(!P)
        {
            Error("Out of space!\n");
            break;
        }
        P->Data = X;
        P->Next = NULL;
        Q->Next = P;
        Q = P;
    }
    return L;
}

int GetListLength(List L)
{
    PtrToNode P;
    P = L->Next;
    int length = 1;
    while(P->Next != NULL)
    {
        P = P->Next;
        length++;
    }
    return length;
}

ElementType GetElement(List L, int i)
{
    int j = 1;
    PtrToNode P;
    P = L->Next;
    while(P != NULL && j < i){
        P = P->Next;
        j++;
    }
    return P->Data;
}

Status IsEmpty(List L)
{
    if(L->Next == NULL)
    {
        return TRUE;
    }
    return FALSE;
}

Status MakeEmpty(List L)
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

Position FindElement(List L, ElementType X)
{
    PtrToNode P;
    P = L->Next;
    while(P != NULL && P->Data != X)
    {
        P = P->Next;
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

Position FindPrevious(List L, ElementType X)
{
    PtrToNode P;
    P = L;
    while(P->Next != NULL && P->Next->Data != X)
    {
        P = P->Next;
    }
    if(P->Next == NULL){
        return NULL;
    }
    return P;
}

Position FindNthNodefromEnd(List L, int N)
{
    if(N <= 0)
    {
        Error("Wrong Index!\n");
        return NULL;
    }
    PtrToNode P, Q;
    P = Q = L->Next;
    int i = 1;
    while(i < N && P->Next)
    {
        P = P->Next;
        i++;
    }
    if(!P->Next)
    {
        Error("Wrong Index!\n");
        return NULL;
    }
    P = P->Next;
    while(P != NULL)
    {
        P = P->Next;
        Q = Q->Next;
    }
    return Q;
}

Status InsertbyPtr(List L, Position P, ElementType X)
{
    PtrToNode newNode, Q;
    newNode = (PtrToNode)malloc(sizeof(struct Node));
    if(!newNode)
    {
        Error("Out of space!\n");
        return ERROR;
    }
    newNode->Data = X;
    Q = P->Next;
    P->Next = newNode;
    newNode->Next = Q;
    return OK;
}

Status InsertbyIndex(List L, int index, ElementType X)
{
    if(index <= 0)
    {
        Error("Wrong index! Insert failed!\n");
        return ERROR;
    }
    PtrToNode P, Q, newNode;
    P = L;
    int i = 1;
    while(P != NULL && i < index)
    {
        P = P->Next;
        i++;
    }
    if(P == NULL){
        Error("Wrong index! Insert failed!\n");
        return ERROR;
    }
    InsertbyPtr(L, P, X);
    return OK;
}

Status DeletebyPtr(List L, Position P)
{
    if(P == NULL || P->Next == NULL)
    {
        return ERROR;
    }
    PtrToNode Q;
    Q = P->Next;
    P->Next = Q->Next;
    free(Q);
    return OK;
}

Status DeletebyElement(List L, ElementType X)
{
    Position P;
    P = FindPrevious(L, X);
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
    PtrToNode P, Q;
    P = L;
    if(index <= 0)
    {
        Error("Wrong index!\n");
        return ERROR;
    }
    int i = 1;
    while(P->Next != NULL && i < index)
    {
        P = P->Next;
        i++;
    }
    if(!P->Next) 
    {
        Error("Wrong index!\n");
        return ERROR;
    }
    DeletebyPtr(L, P);
    return OK;
}

List MergeList(List La, List Lb)
{
    PtrToNode P, Q, T;
    List Lc;
    P = La->Next;
    Q = Lb->Next;
    Lc = La;
    T = Lc;
    while(P != NULL && Q != NULL)
    {
        if(P->Data < Q->Data)
        {
            T->Next = P;
            P = P->Next;
        }else{
            T->Next = Q;
            Q = Q->Next;
        }
        T = T->Next;
    }
    if(P == NULL){
        T->Next = Q;
    }else{
        T->Next = P;
    }
    return Lc;
}

Status ReverseList(List L)
{
    PtrToNode P, Q, head;
    P = L->Next;
    L->Next = NULL;
    head = NULL;
    while(P != NULL)
    {
        Q = P->Next;
        P->Next = head;
        head = P;
        P = Q;
    }
    L->Next = head;
    return OK;
}

void PrintList(List L)
{
    if(!IsEmpty(L)){
        PtrToNode P;
        P = L->Next;
        while(P != NULL)
        {
            printf("%d ", P->Data);
            P = P->Next;
        }
        printf("\n");
    }
}

Status DestroyList(List L)
{
    MakeEmpty(L);
    free(L); 
    return OK;
}