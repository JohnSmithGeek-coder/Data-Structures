#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*-------------------------------------------------------------------
 * Function:    InitList
 * Purpose:     Initialize list
 * Return val:  OK Initialization successful 
 *              OVERFLOW Failed to apply for memory
 *-------------------------------------------------------------------*/
Status InitList(List *L)
{
    L->elem = (ElementType *)malloc(sizeof(ElementType) * LIST_INIT_SIZE);
    if(!L->elem)
    {
        return OVERFLOW;
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

int FindElement(List *L, ElementType e)
{
    int i;
    for(i = 0; i < L->length; i++)
    {
        if(L->elem[i] == e)
        {
            return i;
        }
    }
    return -1;
}

Status LocateElem(List *L, ElementType e)
{
    if(FindElement(L, e) != -1)
    {
        return TRUE;
    }
    return FALSE;
}

/*Return true if L is empty*/
Status IsListEmpty(List *L)
{
    if(L->length == 0)
    {
        return TRUE;
    }
    return FALSE;
}

/*Return the length of the list*/
Status getListLength(List *L)
{
    return L->length;
}

/*-------------------------------------------------------------------
 * Function:    ListInsert
 * Purpose:     Insert an element at the specified location in the list
 * Arguments:   list, position, element   
 * Return val:  OK Insert successful
 *              OVERFLOW Failed to apply for memory
 *-------------------------------------------------------------------*/
Status ListInsert(List *L, int index, ElementType e)
{
    if(L->length >= L->listsize)
    {
        ElementType *newbase;
        newbase = (ElementType *)realloc(L->elem, sizeof(ElementType) * (L->listsize + LISTINCREMENT));
        L->listsize += LISTINCREMENT;
        if(!newbase){
            return OVERFLOW;
        }
        L->elem = newbase;
    }
    int i = L->length;
    while(i >= index){
        L->elem[i] = L->elem[i - 1];
        i--;
    }
    L->elem[i] = e;
    L->length++;
    return OK;
}

/*-------------------------------------------------------------------
 * Function:    ListElemDelete
 * Purpose:     Delete an specified element from the list
 * Return val:  OK Delete successful 
 *              ERROR No such element
 *-------------------------------------------------------------------*/
Status ListElemDelete(List *L, ElementType e)
{
    int i = 0;
    while(L->elem[i] != e && i < L->length)
    {
        i++;
    }
    if(i == L->length){
        return ERROR;
    }
    while(i < L->length - 1)
    {
        L->elem[i] = L->elem[i + 1];
        i++;
    }
    L->length--;
    return OK;
}

/*-------------------------------------------------------------------
 * Function:    ListPositionDelete
 * Purpose:     Delete an element at specified position in the list
 * Return val:  OK Delete successful 
 *              ERROR No such position
 *-------------------------------------------------------------------*/
Status ListPositionDelete(List *L, int index)
{
    if(index <= 0 || index > L->length)
    {
        return ERROR;
    }
    int i = index - 1;
    while(i < L->length - 1)
    {
        L->elem[i] = L->elem[i + 1];
        i++;
    }
    L->length--;
    return OK;
}

void PrintList(List *L)
{
    if(IsListEmpty(L))
    {
        printf("List is empty!\n");
        return;
    }
    int i;
    for(i = 0; i < L->length; i++)
    {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}