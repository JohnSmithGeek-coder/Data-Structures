#ifndef _STACK_H_
#define _STACK_H_

#define OK true
#define ERROR false
#define Error printf

typedef bool Status;

template <class ElementType, int n>
class Stack
{
private:
    int top;
    int MaxSize;
    ElementType *arr;
public:
    Stack();
    ~Stack();
    bool IsEmpty() const;
    bool IsFull() const;
    Status MakeEmpty();
    ElementType GetTop() const;
    int GetSize() const;
    ElementType Pop();
    Status Push(ElementType X);
};

template <class ElementType, int n>
Stack<ElementType, n>::Stack(/* args */)
{
    arr = new ElementType[n];
    top = -1;
    MaxSize = n;
}

template <class ElementType, int n>
Stack<ElementType, n>::~Stack()
{
    delete [] arr;
}

template <class ElementType, int n>
bool Stack<ElementType, n>::IsEmpty() const
{
    return top == -1;
}

template <class ElementType, int n>
bool Stack<ElementType, n>::IsFull() const
{
    return top + 1 == MaxSize;
}

template <class ElementType, int n>
Status Stack<ElementType, n>::MakeEmpty()
{
    top = -1;
    return OK;
}

template <class ElementType, int n>
ElementType Stack<ElementType, n>::GetTop() const
{
    if(!IsEmpty())
    {
        return arr[top];
    }
    ElementType X;
    return X;
}

template <class ElementType, int n>
int Stack<ElementType, n>::GetSize() const
{
    return top + 1;
}

template <class ElementType, int n>
ElementType Stack<ElementType, n>::Pop()
{
    ElementType T;
    if(!IsEmpty())
    {
        T = arr[top];
        top--;
        return T;
    }
    Error("Stack is empty!\n");
    ElementType X;
    return X;
}

template <class ElementType, int n>
Status Stack<ElementType, n>::Push(ElementType X)
{
    if(!IsFull())
    {
        arr[++top] = X;
        return OK;
    }
    Error("Stack is full!\n");
    return ERROR;
}

#endif
