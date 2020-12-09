#include <iostream>
#include "IntStack.h"
#include "test_intstack.h"

int main()
{
    TestIntStack();

    IntStack st(4);
    IntStack st2 = st;

    st.push(10);
    st.push(20);
    st2.push(30);
    st.print();
    st2.print();

    return 0;
}