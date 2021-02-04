/**
 * @file test-trad.cpp
 * @author Louis SIMON
 * @brief Fichier contenant les tests
 * @date 2021-01-24
 * 
 */
#include <iostream>
#include <string>
#include "frtomorse.cpp"
#include "morsetowav.cpp"
#include "wavtomorse.cpp"
#include "morsetofr.cpp"


Map mappe;
std::string francais = "essai", morse = ". ... ... .- .. ";

void map_construction(){
    std::cout << "tests frtomorse.cpp" << std::endl;
    std::cout<< "Test construction" <<std::boolalpha<< " *** " << (mappe.mapmorse.size() != 0) << std::endl;
    }
void map_translate(){
    std::cout << "Test traduction fr -> morse" << std::boolalpha << " *** "<< (mappe.Translate(francais)==morse) <<std::endl;
}

Morse mors(morse);

void morse_construction(){
    std::cout << std::endl <<"tests morsetowav.cpp" << std::endl;
    std::cout << "Test construction" << std::boolalpha << " *** " <<( (mors.blanc.size() != 0) & (mors.ta.size() != 0) & (mors.ti.size() != 0) )<< std::endl;
}

void morse_taille(){
    std::cout<< "Test tailleMessage" << std::boolalpha<< " *** "<< (mors.tailleMessage() == 34) <<std::endl;
}