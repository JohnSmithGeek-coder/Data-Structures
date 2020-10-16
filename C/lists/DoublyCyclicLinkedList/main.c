#include <stdio.h>
#include <stdlib.h>
#include "DCLList.h"

void printinfo(void);

int main(void)
{
    printf("---This program will create a list to store your data!---\n");
    printf("Please input the number of data and datas:\n");
    printf(">>>");
    List L;
    L = CreateList();
    int flag, t = 0;
    int length, X, Y, index, k;
    ElementType e;
    while(TRUE)
    {
        printinfo();
        scanf("%d", &flag);
        switch(flag){
            case 1:
                length = GetListLength(L);
                printf(">>> The length of list is %d\n", length);
                break;
            case 2:
                printf("Please input the element you want to determine:\n>>>");
                scanf("%d", &X);
                if(LocateElem(L, X))
                {
                    printf(">>>Yes, it is in the list.\n");
                }else{
                    printf(">>>No, it is not in the list.\n");
                }
                break;
            case 3:
                printf("Please input the element you want to delete:\n>>>");
                scanf("%d", &Y);
                if(DeletebyElement(L, Y))
                {
                    printf(">>>Delete successfully!\n");
                    PrintList(L);
                }
                break;
            case 4:
                printf("Please input the position of the element you want to delete:\n>>>");
                scanf("%d", &index);
                if(DeletebyIndex(L, index))
                {
                    printf(">>>Delete successfully!\n");
                    PrintList(L);
                }
                break;
            case 5:
                printf("Please input the position and element you want to insert:\n>>>");
                scanf("%d %d", &k, &e);
                if(InsertbyIndex(L, k, e))
                {
                    printf(">>>Insert successfully!\n");
                    PrintList(L);
                }
                break;
            case 6:
                t = 1;
                break;
        }
        if(t == 1){
            break;
        }
    }
    return 0;
}

void printinfo(void)
{
    printf("------------------------------------------------------------\n");
    printf("---1. Get the length of the list.---------------------------\n");
    printf("---2. Determine whether an elelment is in the list.---------\n");
    printf("---3. Delete an element from the list.----------------------\n");
    printf("---4. Delete an element from the list by its position.------\n");
    printf("---5. Insert an element in the list.------------------------\n");
    printf("---6. Quit.-------------------------------------------------\n");
    printf("------------------------------------------------------------\n");
    printf("Please choose a number:\n>>>");
}