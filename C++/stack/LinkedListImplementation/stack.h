#ifndef _STACK_H_
#define _STACK_H_

#define OK true
#define ERROR false
#define Error printf

typedef bool Status;

template <class ElementType>
class Stack
{
    private:
        struct Node;
        typedef struct Node * StackNode;
        typedef StackNode LStack;
        struct Node
        {
            ElementType Data;
            StackNode Next;
        };

        StackNode S;
        StackNode Top;
        int size;
    public:
        Stack();
        ~Stack();
        bool IsEmpty() const;
        ElementType GetTop() const;
        int GetSize() const;
        Status Push(ElementType X);
        ElementType Pop();
        Status MakeEmpty();
};

template <class ElementType>
Stack<ElementType>::Stack()
{
    S = new Node;
    S->Next = NULL;
    Top = S;
    size = 0;
}

template <class ElementType>
Stack<ElementType>::~Stack()
{
    MakeEmpty();
    delete S;
}

template <class ElementType>
bool Stack<ElementType>::IsEmpty() const
{
    if(!S->Next)
    {
        return true;
    }
    return false;
}

template <class ElementType>
ElementType Stack<ElementType>::GetTop() const
{
    if(!IsEmpty())
    {
        return S->Next->Data;
    }
    Error("Stack is empty!\n");
    ElementType X;
    return X;
}

template <class ElementType>
int Stack<ElementType>::GetSize() const
{
    return size;
}

template <class ElementType>
Status Stack<ElementType>::Push(ElementType X)
{
    StackNode P;
    P = new Node;
    if(!P)
    {
        Error("Out of space!!!\n");
        return ERROR;
    }
    P->Data = X;
    P->Next = S->Next;
    S->Next = P;
    size++;
    return OK;
}

template <class ElementType>
ElementType Stack<ElementType>::Pop()
{
    ElementType T;
    if(!IsEmpty())
    {
        StackNode P;
        P = S->Next;
        T = P->Data;
        S->Next = P->Next;
        delete P;
        size--;
        return T;
    }
    Error("Stack is empty!\n");
    ElementType X;
    return X;
}

template <class ElementType>
Status Stack<ElementType>::MakeEmpty()
{
    while(!IsEmpty())
    {
        Pop();
    }
    return OK;
}

#endif