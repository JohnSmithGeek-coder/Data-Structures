## 栈-数组实现

定义一个栈对象：

```c++
Stack<Typen, n> S;/*Type 为 int 或 char 之类的数据类型, n为栈的最大容量*/
```

### bool IsEmpty()

  + 功能：判断栈是否为空
  + 参数：无
  + 返回值：为空返回true，不为空返回false
  + 输入：无
  + 输出：无

### bool IsFull()

  + 功能：判断栈是否为满
  + 参数：无
  + 返回值：栈已满返回true，否则返回false
  + 输入：无
  + 输出：无

### Status MakeEmpty()

  + 功能：置空栈
  + 参数：无
  + 返回值：置空成功返回OK(1)
  + 输入：无
  + 输出：无

### int GetSize()

  + 功能：返回栈长度
  + 参数：无
  + 返回值：栈长度
  + 输入：无
  + 输出：无

### ElementType GetTop()

  + 功能：返回栈顶元素

  + 参数：无

  + 返回值：栈第一个元素的值，若为空则返回任意值

    ！！！所以**一定要和IsEmpty()配合使用**，不然可能会出现不可预知的结果

  + 输入：无

  + 输出：无

###  Status Push(ElementType X)

  + 功能：将元素X压栈
  + 参数：元素X
  + 返回值：成功返回OK，若栈已满则返回ERROR
  + 输入：无
  + 输出：无

### ElementType Pop()

  + 功能：使栈顶元素出栈

  + 参数：无

  + 返回值：栈顶元素，若栈为空，则任意返回一个值

    ！！！所以**一定要和IsEmpty()配合使用**，不然可能会出现不可预知的结果

  + 输入：无
  + 输出：无