#include <iostream>
#include "IntStack.h"

void TestIntStack()
{
    std::cout << "-------------------TEST-------------------" << std::endl;
    std::cout << "La taille d'une pile est un entier strictement positif" << std::endl;

    IntStack stempty(2);
    IntStack stfull(1);
    stfull.push(10);

    IntStack st(4);
    std::cout << "Création d'une pile : IntStack st(4)" << std::endl;

    std::cout << "Affichage : st.print() renvoie : ";
    st.print();

    std::cout << std::boolalpha << "Test vide : st.is_empty() renvoie : " << st.is_empty() << std::endl;

    st.push(10);
    std::cout << "Ajout d'un élément : st.push(10) puis st.print() renvoie : ";
    st.print();

    st.push(20);
    st.push(30);
    st.push(40);
    std::cout << "On pousse 20, 30 et 40 et on affiche : ";
    st.print();

    std::cout << std::boolalpha << "Test plein : st.is_full() renvoie : " << st.is_full() << std::endl;

    std::cout << "st.pop() renvoie : " << st.pop() << std::endl;
    std::cout << "On affiche la pile : ";
    st.print();
    std::cout << std::endl;

    std::cout << "TEST ERREURS : " << std::endl;

    std::cout << "IntStack badst(-2) renvoie : ";
    try
    {
        IntStack badst(-2);
    }
    catch (const char *erreur)
    {
        std::cerr << erreur << '\n';
    }

    std::cout << "st.pop([[) renvoie : ";
    try
    {
        stempty.pop();
    }
    catch (const char *erreur)
    {
        std::cerr << erreur << '\n';
    }

    std::cout << "st.push(10) si st est pleine renvoie : ";
    try
    {
        stfull.push(10);
    }
    catch (const char *erreur)
    {
        std::cerr << erreur << '\n';
    }
    std::cout << "-----------------FIN TEST-----------------" << std::endl
              << std::endl;
}