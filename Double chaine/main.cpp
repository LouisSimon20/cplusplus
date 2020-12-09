#include <iostream>
#include "intlist.h"
#include "TestIntList.h"

int main()
{
    //TestIntList();


    IntList l;
    l.add_front(10);
    l.add_front(11);
    l.add_front(12);
    l.print();
    l.add_back(9);
    l.add_back(8);
    l.print();
    //l.remove_front();
    l.print();
    std::cout << l.search(5) << "\n" << l.search(10) << std::endl;
    //l.remove(10);
    l.print();
    return 0;
}
