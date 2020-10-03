[TOC]

## 线性表-数组实现

```c
/*Struct for list*/
typedef struct{
    ElementType *elem;
    int length;
    int listsize;
}List;
```



###  Status InitList(List *L)

  + 功能：初始化一个线性表
  + 参数：指向线性表的指针
  + 返回值：初始化成功返回OK(1), 初始化失败返回ERROR(0)
  + 输入：无
  + 输出：无

### int FindElement(List *L, ElementType e)

  + 功能：找到元素在线性表中的位置
  + 参数：指向线性表的指针，要查找的元素e
  + 返回值：若找到返回元素下标，若没找到返回-1
  + 输入：无
  + 输出：无

### Status LocateElem(List *L, ElementType e)

  + 功能：确定一个元素有没有在线性表中
  + 参数：指向线性表的指针，元素e
  + 返回值：找到返回TRUE(1)，没找到返回FALSE(0)
  + 输入：无
  + 输出：无

### Status IsListEmpty(List *L)

  + 功能：判断线性表是否为空
  + 参数：指向线性表的指针
  + 返回值：为空返回TRUE(1)，不为空返回FALSE(0)
  + 输入：无
  + 输出：无

### int getListLength(List *L)

  + 功能：获得链表的长度
  + 参数：指向线性表的指针
  + 返回值：链表的长度
  + 输入：无
  + 输出：无

### Status ListInsert(List *L, int index, ElementType e)

  + 功能：插入一个元素到线性表的指定位置
  + 参数：指向链表的指针，位置index，要插入的元素e
  + 返回值：插入成功返回OK(1)，插入失败返回ERROR(0)
  + 输入：无
  + 输出：无

### Status ListElemDelete(List *L, ElementType e)

  + 功能：从线性表中删除元素e
  + 参数：指向链表的指针，元素e
  + 返回值：删除成功返回OK(1)，失败返回ERROR(0)
  + 输入：无
  + 输出：无

### Status ListPositionDelete(List *L, int index)

  + 功能：从线性表删除指定位置的的元素
  + 参数：指向线性表的指针，位置index
  + 返回值：删除成功返回OK(1)，失败返回ERROR(0)
  + 输入：无
  + 输出：无

