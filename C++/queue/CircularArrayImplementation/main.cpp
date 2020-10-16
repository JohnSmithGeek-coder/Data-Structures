#include <iostream>
#include <new>
#include "queue.h"

void printinfo();

int main(void)
{
    std::cout << "*****This is a program to test the library of Queue.******" << std::endl;
    std::cout << "Please input some integer to store by Queue (end by -1).\n>>>";
    Queue<int, 3> Q;
    int num;
    std::cin >> num;
    while(num != -1)
    {
        Q.Enqueue(num);
        std::cin >> num;
    }
    int flag, t;
    int k = 0;
    while(true)
    {
        printinfo();
        std::cin >> flag;
        switch(flag)
        {
            case 1:
                if(!Q.IsEmpty())
                {
                    std::cout << "The first element is " << Q.GetFirst() << "." << std::endl;
                }else{
                    std::cout << "Queue is empty.\n";
                }
                break;
            case 2:
                std::cout << "The size of Queue is " << Q.GetSize() << "." << std::endl;
                break;
            case 3:
                if(Q.IsFull())
                {
                    Error("Queue is full!\n");
                    break;
                }
                std::cout << "Please input a number you want to enqueue.\n>>>";
                std::cin >> t;
                Q.Enqueue(t);
                std::cout << t << " is enqueued.\n";
                break;
            case 4:
                if(!Q.IsEmpty())
                {
                    std::cout << Q.Dequeue() << " is dequeued.\n";
                }else{
                    std::cout << "Queue is empty.\n";
                } 
                break;
            case 5:
                if(Q.IsEmpty())
                {
                    std::cout << "Queue is empty.\n>>>";
                }else{
                    std::cout << "Queue is not empty.\n>>>";
                }
                break;
            case 6:
                k = 1;
                break;
        }
        if(k)
        {
            break;
        }
    }
    return 0;
}

void printinfo()
{
    std::cout << "-+-------------------------------------------+-" << std::endl
              << " | 1. View the First element.                | " << std::endl
              << " | 2. Get the size of Queue.                 | " << std::endl
              << " | 3. Enqueue an element.                    | " << std::endl
              << " | 4. Dequeue an element.                    | " << std::endl
              << " | 5. Determine whether the Queue is empty.  | " << std::endl
              << " | 6. Quit.                                  | " << std::endl
              << "-+-------------------------------------------+-" << std::endl;
    std::cout << "Please choose a number.\n>>>";
}