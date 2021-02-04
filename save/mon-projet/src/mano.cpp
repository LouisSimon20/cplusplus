#include "stack.h"
#include "vert.h"
#include <iostream>
namespace mylib{
    void info(char cara){
        std::cout << cara << std::endl;
    }
}

class X{};
std::ostream& operator<< (std::ostream& os, X& x){
        os << "Je suis de type X";
        return os;
    }

int Vert::radius = 12;

int main(){
    IntStack<int, 3> st;
    X x;
    std::cout << x << std::endl;
    mylib::info('a');
    return 0;
}