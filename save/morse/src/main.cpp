/**
 * @file main.cpp
 * @author Louis SIMON
 * @date 2021-01-23
 */

#include <iostream>
#include <string>
#include "frtomorse.cpp"
#include "morsetowav.cpp"
#include "wavtomorse.cpp"
#include "morsetofr.cpp"

/**
 * @brief Fonction permettant de nettoyer le stream (utile dans le menu de choix)
 * 
 */
void clear(){    
  while ( getchar() != '\n' );
}

/**
 * @brief Fonction proposant un menu permettant de choisir entre encodage et decodage d'un message morse
 * 
 * @return int correspondant a l'option du menu choisi
 */
int Menu(){
    int choix=0;
    bool err=false;
    do{
        std::cout<< "------MENU------" << std::endl;
        std::cout<< "1 : Encodage    " << std::endl;
        std::cout<< "2 : Decodage    " << std::endl;
        std::cout<< "3 : Quitter     " << std::endl;
        std::cout<< "----------------" << std::endl << std::endl;
        if (err){
            std::cout<<"Mauvais numero : ";
        }
        std::cout<< "Entrez le numero correspondant : ";
        std::cin>>choix;
        err=true;
        clear();
        std::cout << std::endl;
    }while(choix > 3 or choix <= 0);
    return choix;
}

/**
 * @brief Fonction permettant de décoder un message audio (wav) et d'afficher le message
 * 
 */
void decodage(){
    std::cout << "----DECODAGE----" << std::endl;
    std::cout << "Attention, seuls les 26 lettres de l'alphabet sont autorisées" << std::endl;
    std::cout << "Entrer le chemin d'un fichier wav à traduire : ";
    std::string chemin;
    getline(std::cin, chemin);
    Wav wave(chemin.c_str());
    wave.acq_entete();
    if(wave.verif_entete()){
        wave.acq_data();
        wave.decoupage();
        wave.translatemorse();
        Arbre tree(wave.morse);
        tree.morsetofr();
        std::cout << "Message : " << tree.fr << std::endl;
        }

    else{
        std::cout << "erreur à la lecture de l'entête du fichier" << std::endl;
    }
}

/**
 * @brief Fonction permettant d'encoder le francais en fichier son, en choisissant la provenance du texte et le nom du fichier à produire
 * 
 */
void encodage(){
    std::cout << "----ENCODAGE----" << std::endl;
    std::cout << "Entrer le texte à traduire ou le chemin d'un fichier de texte." << std::endl;
    std::cout << "Les caractères autorisées sont les lettres sans accent, les chiffres et" <<std::endl; 
    std::cout << "une ponctuation basique : ,.:;?!=-+/()'@$_&" << std::endl << std::endl;
    std::cout << "Texte/chemin : ";
    Map mappe;
    mappe.Acquire();

    std::cout << std::endl << "Entrer le chemin du fichier son à produire (avec extension)" << std::endl;
    std::cout << "Chemin : ";
    Morse mors(mappe.mo);
    mors.Acquire();
    mors.translateMtoW();
}

int main(){
    int choix = Menu();
    switch(choix){
        case 1: encodage();
                break;
        case 2: decodage();
                break;
    }
    return 0;
}