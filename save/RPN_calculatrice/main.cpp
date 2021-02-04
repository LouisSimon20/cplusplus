#include <iostream>
#include "calc.h"
#include "test-calculatrice.h"

int main(const int argc, const char* argv[]){
    TestRpnCalc();
    std::cout << rpn_eval(argc-1, argv+1) << std::endl;
    return 0;
}