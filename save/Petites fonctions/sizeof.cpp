#include <iostream>
//C'est une autre fonction en fait

int main(){
    int tab[2];
    tab[0] = 42;
    tab[1] = 47;
    // tab[i] = *(tab + i)
    std::cout << tab << ' ' << *tab << ' ' << *(tab+1) << std::endl;
    return 0;
}