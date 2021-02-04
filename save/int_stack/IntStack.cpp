#include <iostream>
#include "IntStack.h"

IntStack::IntStack(int taille) : size(taille), top(0)
{
    if (taille > 0)
        stack = new int[size];
    else
    {
        throw("Wrong size : the size must be a positive integer");
    }
}
IntStack::IntStack( IntStack& rst) : size(rst.size), top(rst.top), stack(new int[size]){
    for(int i; i<top; i++){
        stack[i] = rst.stack[i];
    }
}

IntStack::~IntStack()
{
    delete[] stack;
}
void IntStack::push(int a)
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
int IntStack::pop()
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
bool IntStack::is_empty()
{
    return top == 0;
}
bool IntStack::is_full()
{
    return top == size;
}
void IntStack::print()
{
    std::cout << "[";
    for (int i = 0; i < top; i++)
    {
        std::cout << stack[i] << " ";
    }
    std::cout << "[" << std::endl;
}