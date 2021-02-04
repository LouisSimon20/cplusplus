#pragma once
#include <iostream>

template <typename T, int SIZE>
class IntStack
{

public:
    void push(T a);
    T pop();
    bool is_empty();
    bool is_full();
    void print();

private:
    T stack[SIZE];
    int top=0;
};

template <typename T, int SIZE>
inline void IntStack<T, SIZE>::push(T a)
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

template <typename T, int SIZE>
inline T IntStack<T, SIZE>::pop()
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

template <typename T, int SIZE>
inline bool IntStack<T, SIZE>::is_empty()
{
    return top == 0;
}

template <typename T, int SIZE>
inline bool IntStack<T, SIZE>::is_full()
{
    return top == SIZE;
}

template <typename T, int SIZE>
inline void IntStack<T, SIZE>::print()
{
    std::cout << "[";
    for (int i = 0; i < top; i++)
    {
        std::cout << stack[i] << " ";
    }
    std::cout << "[" << std::endl;
}