/**
 * @file frtomorse.cpp
 * @author Louis SIMON
 * @brief Fichier contenant la classe Map
 * @date 2021-01-24
 * 
 */

#include <iostream>
#include <cstring>
#include <map>
#include <iterator>
#include <fstream>
/**
 * @brief Classe permettant de passer du francais au morse (.--) 
 * 
 */
class Map{
    friend void encodage();
    friend void map_construction();
public:
    /**
     * @brief Construct a new Map object
     * 
     * Initialise le dictionnaire permettant de passer du francais au morse
     * 
     */
    Map(){
        mapmorse['a'] = ".- ";
        mapmorse['b'] = "-... ";
        mapmorse['c'] = "-.-. ";
        mapmorse['d'] = "-.. ";
        mapmorse['e'] = ". ";
        mapmorse['f'] = "..-. ";
        mapmorse['g'] = "--. ";
        mapmorse['h'] = ".... ";
        mapmorse['i'] = ".. ";
        mapmorse['j'] = ".--- ";
        mapmorse['k'] = "-.- ";
        mapmorse['l'] = ".-.. ";
        mapmorse['m'] = "-- ";
        mapmorse['n'] = "-. ";
        mapmorse['o'] = "--- ";
        mapmorse['p'] = ".--. ";
        mapmorse['q'] = "--.- ";
        mapmorse['r'] = ".-. ";
        mapmorse['s'] = "... ";
        mapmorse['t'] = "- ";
        mapmorse['u'] = "..- ";
        mapmorse['v'] = "...- ";
        mapmorse['w'] = ".-- ";
        mapmorse['x'] = "-..- ";
        mapmorse['y'] = "-.-- ";
        mapmorse['z'] = "--.. ";
                //CHIFFRES
        mapmorse['0'] = "----- ";
        mapmorse['1'] = ".---- ";
        mapmorse['2'] = "..--- ";
        mapmorse['3'] = "...-- ";
        mapmorse['4'] = "....- ";
        mapmorse['5'] = "..... ";
        mapmorse['6'] = "-.... ";
        mapmorse['7'] = "--... ";
        mapmorse['8'] = "---.. ";
        mapmorse['9'] = "----. ";
            //PONCTUATIONS
        mapmorse[' '] = "/ ";
        mapmorse['.'] = ".-.-.- ";
        mapmorse[','] = "--..-- ";
        mapmorse['?'] = "..--.. ";
        mapmorse['!'] = "-.-.-----. ";
        mapmorse['/'] = "-..-. ";
        mapmorse['('] = "-.--. ";
        mapmorse[')'] = "-.--.- ";
        mapmorse['&'] = ".-... ";
        mapmorse[':'] = "---... ";
        mapmorse[';'] = "-.-.-. ";
        mapmorse['='] = "-...- ";
        mapmorse['+'] = ".-.-. ";
        mapmorse['-'] = "-....- ";
        mapmorse['_'] = "..--.- ";
        mapmorse['"'] = ".-..-. ";
        mapmorse['$'] = "...-..- ";
        mapmorse['@'] = ".--.-. ";
            //Cas particulier : " ' "
        mapmorse[static_cast<char>(39)] = ".----. ";
    }

    /**
     * @brief Convertit le francais en morse.
     * 
     * Utilise le dictionnaire mapmorse pour réaliser cette fonction.
     * 
     * @param francais message en francais
     * @return std::string morse - message en morse
     */
    std::string Translate(std::string francais){
        std::string morse;
        char cara;
        for(int i=0; i<strlen(francais.c_str());i++){
            cara = francais[i];
            morse.append(mapmorse[tolower(cara)]);
        }
        return morse;
    }
    /**
     * @brief Acquérit et stocke le message en francais
     * 
     * Dans le cas d'un message donné dans le terminal, il suffit de stocker cette entrée. \n
     * Dans le cas d'un lien vers un fichier, on ouvre le fichier pour en extraire le message.
     * 
     */
    void Acquire(){
        getline(std::cin, fr);
        std::ifstream fichier( fr.c_str() );
        if (fichier.fail()){
            //C'est une chaine de caractère
            mo = this->Translate(fr);
        }

        else{
            //c'est un fichier
            std::string fra, ligne;
            while(getline(fichier, ligne)){
                fra.append(ligne);
            }
            mo = this->Translate(fra);
        }
    }
private:
    std::map<char, std::string> mapmorse;
    std::string fr, mo;
};