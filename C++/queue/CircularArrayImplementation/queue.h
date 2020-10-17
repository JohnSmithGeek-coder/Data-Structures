#ifndef _QUEUE_H_
#define _QUEUE_H_

#define OK true
#define ERROR false
#define Error printf

typedef bool Status;

template <class ElementType, int n>
class Queue
{
private:
    int MaxSize;
    int Front;
    int Rear;
    ElementType *arr;
    int size;
public:
    Queue();
    ~Queue();
    bool IsEmpty() const;
    bool IsFull() const;
    Status MakeEmpty();
    int GetSize() const;
    ElementType GetFirst() const;
    Status Enqueue(ElementType X);
    ElementType Dequeue();
};

template <class ElementType, int n>
Queue<ElementType, n>::Queue()
{
    MaxSize = n;
    arr = new ElementType[n];
    size = 0;
    Front = Rear = -1;
}

template <class ElementType, int n>
Queue<ElementType, n>::~Queue()
{
    delete [] arr;
}

template <class ElementType, int n>
bool Queue<ElementType, n>::IsEmpty() const
{
    return (Front == -1 && Rear == -1);
}

template <class ElementType, int n>
bool Queue<ElementType, n>::IsFull() const
{
    return (Rear + 1) % MaxSize == Front;
}

template <class ElementType, int n>
Status Queue<ElementType, n>::MakeEmpty()
{
    Front = Rear = -1;
    return OK;
}

template <class ElementType, int n>
int Queue<ElementType, n>::GetSize() const
{
    return size;
}

template <class ElementType, int n>
ElementType Queue<ElementType, n>::GetFirst() const
{
    if(!IsEmpty())
    {
        return arr[Front];
    }
    ElementType X;
    return X;
}

template <class ElementType, int n>
Status Queue<ElementType, n>::Enqueue(ElementType X)
{
    if(!IsFull())
    {
        Rear = (Rear + 1) % MaxSize;
        arr[Rear] = X;
        if(Front == -1)
        {
            Front = Rear;
        }
        size++;
        return OK;
    }
    Error("Queue is full!\n");
    return ERROR;
}

template <class ElementType, int n>
ElementType Queue<ElementType, n>::Dequeue()
{
    if(!IsEmpty())
    {
        ElementType T;
        if(Front == Rear)
        {
            T = arr[Front];
            Front = Rear = -1;
        }else{
            T = arr[Front];
            Front = (Front + 1) % MaxSize;
        }
        size--;
        return T;
    }
    ElementType X;
    return X;
}

#endif
