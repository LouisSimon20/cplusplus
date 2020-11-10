#include <iostream>
#include "IntStack.h"
#include "test_intstack.h"

int main()
{
    TestIntStack();

    IntStack st(4);

    st.print();
    st.push(10);
    st.print();
    st.push(20);
    st.push(30);
    st.print();

    std::cout << st.pop() << std::endl;
    return 0;
}