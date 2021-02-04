#include <iostream>
//Affiche la longueur d'une chaine de caractère

void strlen(char tab[]){
    int i=0;
    while (tab[i] != '\0'){
        i=i+1;
    }
    std::cout << i << std::endl;
}

int main(){
    char chaine[] = "coucou c'est moi"; // "": chaine, '':caractère
    strlen(chaine);
    return 0;
}