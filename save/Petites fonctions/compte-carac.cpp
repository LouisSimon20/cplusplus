#include <iostream>
void strlen(char tab[]){ //prend en paramètre un tableau de caractere
    int i=0;
    while (tab[i] != '\0'){
        i=i+1;
    }
    std::cout << i << std::endl;
}


int main(int argc, char* argv[]){ //char* est un tableau de pointeur qui vont vers des caractères
    for (int i=1; i<argc; i++)
    strlen(argv[i]);
    return 0;
}