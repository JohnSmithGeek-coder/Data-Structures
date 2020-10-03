[TOC]
## 循环链表

注意：本库的链表均含有一个空头（即头节点为不放置任何元素的空节点）！

### List CreateList(void)
  + 功能：创建一个循环链表
  + 参数：无
  + 返回值：指向头节点的指针
  + 输入：输入一个数字N，其后为N个要存储的数字
  + 输出：无

### Status IsEmpty(List L)
  + 功能：判断链表是否为空
  + 参数：指向头节点的指针
  + 返回值：链表为空返回TRUE(1)，链表不为空返回FALSE(0)
  + 输入：无
  + 输出：无

### int GetListLength(List L)
  + 功能：得到链表的长度
  + 参数：指向头节点的指针
  + 返回值：链表的长度
  + 输入：无
  + 输出：无

### Position GetLast(List L);
  + 功能：得到指向最后一个节点的指针
  + 参数：指向链表头节点的指针
  + 返回值：指向最后一个节点的指针，若链表为空则返回NULL
  + 输入：无
  + 输出：无

### Position FindPrevious(List L, ElementType X)
  + 功能：找到指向元素X前一个结点的指针
  + 参数：指向头节点的指针，元素X
  + 返回值：指向元素X前一个结点的指针，若没有X或链表为空则返回NULL
  + 输入：无
  + 输出：无

### Position FindElement(List L, ElementType X)
  + 功能：找到指向元素X的指针
  + 参数：指向头节点的指针，待查找的元素X
  + 返回值：指向元素X的指针, 若没有X或链表为空则返回NULL
  + 输入：无
  + 输出：无

### Status LocateElem(List L, ElementType X)
  + 功能：确定元素X有没有在链表中
  + 参数：指向头节点的指针，待确定元素X
  + 返回值：X在链表中返回TRUE(1)，X不在链表中返回FALSE(0)
  + 输入：无
  + 输出：无

### Status DeleteFirst(List L, Position Last)
  + 功能：删除第一个节点
  + 参数：指向头节点的指针，指向最后一个节点的指针
  + 返回值：删除成功返回TRUE(1)
  + 输入：无
  + 输出：无

### Status DeletebyPtr(List L, Position P)
  + 功能：删除指针P指向的节点的后一个节点
  + 参数：指向头节点的指针，指针P
  + 返回值：删除成功则返回OK(1)，删除失败返回ERROR(0)
  + 输入：无
  + 输出：无

### Status DeletebyElement(List L, ElementType X)
  + 功能：删除元素X所在的节点
  + 参数：指向头节点的指针，元素X
  + 返回值：删除成功则返回OK(1)，删除失败返回ERROR(0)
  + 输入：无
  + 输出：若无X，输出"No such element! Delete failed!"

### Status DeletebyIndex(List L, int index)
  + 功能：删除指定位置的节点
  + 参数：指向头节点的指针，位置index
  + 返回值：删除成功则返回OK(1)，删除失败返回ERROR(0)
  + 输入：无
  + 输出：若index错误，输出"Wrong Index! Delete failed!"

### Status InsertFirst(List L, ElementType X)
  + 功能：在头节点后插入一个节点
  + 参数：指向头节点的指针，元素X
  + 返回值：插入成功则返回OK(1)，插入失败返回ERROR(0)
  + 输入：无
  + 输出：若N错误，输出"Wrong Index!"

### Status InsertbyPtr(List L, Position P, ElementType X)
  + 功能：在指针P指向的节点**后**插入一个节点
  + 参数：指向头节点的指针，指向插入位置前一个结点的指针，元素X
  + 返回值：插入成功则返回OK(1)，插入失败返回ERROR(0)
  + 输入：无
  + 输出：无

### Status InsertbyIndex(List L, int index, ElementType X)
  + 功能：在确定位置处插入节点
  + 参数：指向头节点的指针，待插入的位置，元素X
  + 返回值：插入成功则返回OK(1)，插入失败返回ERROR(0)
  + 输入：无
  + 输出：若index错误，输出"Wrong Index!  Insert failed!"

### Status ListAppend(List L, ElementType X)
  + 功能：在链表末尾添加一个节点
  + 参数：指向头节点的指针，元素X
  + 返回值：插入成功则返回OK(1)，插入失败返回ERROR(0)
  + 输入：无
  + 输出：无

### void PrintList(List L)
  + 功能：打印链表中的元素
  + 参数：指向链表头节点的指针
  + 返回值：无
  + 输入：无
  + 输出：链表中的元素