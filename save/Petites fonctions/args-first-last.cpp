#include <iostream>

// Affiche le premier et dernier élément passé(s) en fonction du main

int main(int argc, char* argv[]){
    if (argc == 1) std::cout << argv[0] << std::endl;
    else std::cout << *argv << std::endl << *(argv + (argc-1)) << std::endl; //argv[0] == *argv
    return 0;
}