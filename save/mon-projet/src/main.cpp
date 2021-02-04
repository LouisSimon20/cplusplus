#include <iostream>
#include <cstdlib>
#include "intlist.h"

void test_add_front()
{
  std::cout << "test add front one element with value";
  IntList list;
  int e1 = rand();
  list.add_front(e1);
}

int main()
{
  test_add_front();
  return 0;
}