#include<iostream>
//Echange deux valeurs

void swap_ref(int& ra, int& rb ){
    int aux = ra;
    ra = rb;
    rb = aux;
}

void swap (int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
}
int main () {
   int a = 12;
   int b = 81;
   std::cout << a << ' ' << b << std::endl;
   // affiche 12 81 
   swap ( &a, &b );
   std::cout << a << ' ' << b << std::endl;
   // affiche 81 12
   swap_ref(a, b);
   std::cout << a << ' ' << b << std::endl;
   // affiche 12 81 

}