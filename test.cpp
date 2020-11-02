#include <iostream>
#include "calc.h"

int main(int argc, char* argv[]){
    std::cout << rpn_eval(argc-1, argv+1) << std::endl;
    return 0;
}