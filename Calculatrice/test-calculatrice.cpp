#include <iostream>
#include "calc.h"
#include "stack.h"

void TestRpnCalc(){
    std::cout << "-------------------TEST-------------------" <<std::endl;
    std::cout << "La calculatrice ne prend que des entiers en opérande" << std::endl;
    std::cout << "La calculatrice ne prend que des expressions bien formées" << std::endl;
    std::cout << "Les opérateurs sont : + - x / !" << std::endl;
    std::cout << "La division par 0 fait planter le programme" << std::endl << std::endl;

    const char expr[] = "x";
    const char a[]  = "123";
    const char* tab [] = {"7", "2", "!", "+"};

    std::cout << std::boolalpha << "is_operand(" << expr <<")  retourne " << is_operand(expr) << std::endl;
    std::cout << std::boolalpha << "is_operand(" << a << ")  retourne " << is_operand(a) << std::endl << std::endl;

    std::cout << std::boolalpha << "is_operand(" << expr << ")  retourne " << is_operand(expr) << std::endl;
    std::cout << std::boolalpha << "is_operand(" << a << ")  retourne " << is_operand(a) << std::endl << std::endl;

    std::cout << std::boolalpha << "is_binary(" << expr << ") retourne " << is_binary(expr) << std::endl << std::endl;

    std::cout << std::boolalpha << "rpn_eval(4, [7, 2, !, x]) retourne " << std::endl << rpn_eval(4, tab) << std::endl;
        std::cout << "-----------------FIN TEST-----------------" <<std::endl<<std::endl;

}
