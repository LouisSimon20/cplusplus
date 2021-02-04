#ifndef INTSTACK_H
#define INTSTACK_H
class IntStack
{
public:
    IntStack(int taille);
    IntStack( IntStack& rst);
    ~IntStack();
    void push(int a);
    int pop();
    bool is_empty();
    bool is_full();
    void print();

private:
    int top;
    int size;
    int *stack;
};
#endif