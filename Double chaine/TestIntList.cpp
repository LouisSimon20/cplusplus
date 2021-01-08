#include <iostream>
#include "intlist.h"

void TestIntList()
{
    std::cout << "-------------------TEST-------------------" << std::endl;

    std::cout << "Création d'une liste : IntList liste1" << std::endl;
    IntList liste1;

    std::cout << "Ajout d'élément en tête : liste1.add_front(1)" << std::endl;
    liste1.add_front(1);
    liste1.add_front(2);
    liste1.add_front(3);
    liste1.add_front(4);

    std::cout << "Affichage : liste1.print() renvoie : ";
    liste1.print();

    std::cout << "Suppression d'un élément en tête : liste1.remove_front()  ";
    liste1.remove_front();
    liste1.print();

    std::cout << std::boolalpha << "Fonction recherche : liste1.search(3) renvoie : " << liste1.search(3) << std::endl;
    std::cout << std::boolalpha << "Fonction recherche : liste1.search(5) renvoie : " << liste1.search(5) << std::endl;

    std::cout << "Suppression de l'élément 2 : liste1.remove(2) : ";
    liste1.remove(2);
    liste1.print();

    std::cout << "Suppression de l'élément  : liste1.remove(1) : ";
    liste1.remove(1);
    liste1.print();

    std::cout << "-----------------FIN TEST-----------------" << std::endl
              << std::endl;
}