// fichier divint.cpp
#include <iostream>
int main(){
    int i=1;
    int j=3;
    std::cout << static_cast<float>(i)/j << std::endl;
    //Permet de 'caster' le int en float en C++
    // sinon float(i) en C
    // std::endl = '\n' : retour à la ligne
    return 0;
}