#include <iostream>

class IntStack
{

public:
    IntStack(int taille) : size(taille), top(0)
    {
        if (taille > 0)
            stack = new int[size];
        else
        {
            throw("Wrong size : the size must be a positive integer");
        }
    }
    ~IntStack()
    {
        delete[] stack;
    }
    void push(int a)
    {
        if (not is_full())
        {
            stack[top] = a;
            top = top + 1;
        }
        else
        {
            throw("Cannot push an element in a full stack");
        }
    }
    int pop()
    {
        if (not is_empty())
        {
            top = top - 1;
            return stack[top];
        }
        else
        {
            throw("Cannot pop an empty stack");
        }
    }
    bool is_empty()
    {
        return top == 0;
    }
    bool is_full()
    {
        return top == size;
    }
    void print()
    {
        std::cout << "[";
        for (int i = 0; i < top; i++)
        {
            std::cout << stack[i] << " ";
        }
        std::cout << "[" << std::endl;
    }

private:
    int top;
    int size;
    int *stack;
};