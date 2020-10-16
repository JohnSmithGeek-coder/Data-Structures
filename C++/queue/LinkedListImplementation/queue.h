#ifndef _QUEUE_H_
#define _QUEUE_H_

#define OK true
#define ERROR false
#define Error printf

typedef bool Status;

template <class ElementType>
class Queue
{
private:
    struct Node;
    typedef struct Node * QueueNode;
    struct Node{
        ElementType Data;
        QueueNode Next;
    };

    QueueNode Front;
    QueueNode Rear;
    int size;

public:
    Queue();
    ~Queue();
    bool IsEmpty();
    Status MakeEmpty();
    int GetSize();
    ElementType GetFirst();
    Status Enqueue(ElementType X);
    ElementType Dequeue();
};

template <class ElementType>
Queue<ElementType>::Queue()
{
    Front = new Node;
    Front->Next = NULL;
    Rear = Front;
    size = 0;
}

template <class ElementType>
Queue<ElementType>::~Queue()
{
    MakeEmpty();
    delete Front;
}

template <class ElementType>
bool Queue<ElementType>::IsEmpty()
{
    return Front == Rear;
}

template <class ElementType>
Status Queue<ElementType>::MakeEmpty()
{
    while(!IsEmpty())
    {
        Dequeue();
    }
    return OK;
}

template <class ElementType>
int Queue<ElementType>::GetSize()
{
    return size;
}

template <class ElementType>
ElementType Queue<ElementType>::GetFirst()
{
    if(!IsEmpty())
    {
        return Front->Next->Data;
    }
    Error("Queue is empty!\n");
    ElementType X;
    return X;
}

template <class ElementType>
Status Queue<ElementType>::Enqueue(ElementType X)
{
    QueueNode Q;
    Q = new Node;
    if(!Q)
    {
        Error("Out of space!\n");
        return ERROR;
    }
    Q->Data = X;
    Q->Next = NULL;
    Rear->Next = Q;
    Rear = Q;
    size++;
    return OK;
}

template <class ElementType>
ElementType Queue<ElementType>::Dequeue()
{
    QueueNode Q;
    ElementType T;
    if(!IsEmpty())
    {
        Q = Front->Next;
        T = Q->Data;
        if(Q == Rear)
        {
            Rear = Front;
        }
        Front->Next = Q->Next;
        delete Q;
        size--;
        return T;
    }
    Error("Queue is empty!\n");
    ElementType X;
    return X;
}

#endif