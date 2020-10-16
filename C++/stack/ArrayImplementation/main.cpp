#include <iostream>
#include <new>
#include "stack.h"

void printinfo();

int main(void)
{
    std::cout << "*****This is a program to test the library of stack.******" << std::endl;
    std::cout << "Please input some integer to store by stack (end by -1).\n>>>";
    Stack<int, 10> S;
    int num;
    std::cin >> num;
    while(num != -1 && !S.IsFull())
    {
        S.Push(num);
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
                if(!S.IsEmpty())
                {
                    std::cout << "The top element is " << S.GetTop() << "." << std::endl;
                }else{
                    std::cout << "Stack is empty.\n";
                }
                break;
            case 2:
                std::cout << "The size of stack is " << S.GetSize() << "." << std::endl;
                break;
            case 3:
                if(S.IsFull())
                {
                    Error("Stack is full!\n");
                    break;
                }
                std::cout << "Please input a number you want to push.\n>>>";
                int t;
                std::cin >> t;
                S.Push(t);
                std::cout << t << " is pushed.\n";
                break;
            case 4:
                if(!S.IsEmpty())
                {
                    std::cout << S.Pop() << " is Popped.\n";
                }else{
                    std::cout << "Stack is empty.\n";
                } 
                break;
            case 5:
                if(S.IsEmpty())
                {
                    std::cout << "Stack is empty.\n>>>";
                }else{
                    std::cout << "Stack is not empty.\n>>>";
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
              << " | 1. View the top element.                  | " << std::endl
              << " | 2. Get the size of stack.                 | " << std::endl
              << " | 3. Push an element in the stack.          | " << std::endl
              << " | 4. Pop the element at the top of stack.   | " << std::endl
              << " | 5. Determine whether the stack is empty.  | " << std::endl
              << " | 6. Quit.                                  | " << std::endl
              << "-+-------------------------------------------+-" << std::endl;
    std::cout << "Please choose a number.\n>>>";
}
