#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "math.h"

int lire_wav(int taille, std::ifstream& fichier){
        int lecture[taille];
        int res=0;
        for(int i=0; i<taille; i++){
            lecture[i] = fichier.get();
            res = (lecture[i] << 8*i) | res;
            //std::cout << lecture[i] << std::endl;
        }
        return res;
    }

void ecrire_little_endian(unsigned int octets, int taille, std::ofstream& fichier){

        unsigned char faible ;
        
        while(taille > 0) {   
            faible = octets & 0x000000FF ;
            fichier<<faible;
            octets = octets >> 8 ;
            taille = taille - 1 ;
        }
    }

int swap(int octets, int taille){
    int b0, b1, b2, b3, res;
    if (taille==4){
        b0 = (octets & 0x000000ff) << 24u;
        b1 = (octets & 0x0000ff00) << 8u;
        b2 = (octets & 0x00ff0000) >> 8u;
        b3 = (octets & 0xff000000) >> 24u;
        res = b0 | b1 | b2 | b3;
    }

    if (taille==2){
        //b0 = (octets & 0x00ff) << 8u;
        //b1 = (octets & 0xff00) >> 8u;
        std::cout << (octets>>8) << " " << ((octets >> 8) & 0x00FF) << std::endl;
        std::cout << (octets<<8) << " " << ((octets << 8) & 0xFF00) << std::endl;

        res = ((octets >> 8) & 0x00FF) | ((octets << 8) & 0xFF00);
    }
    return res;
}

/* void decoupage(){
    int compteur=0, compteur2 = 0;
    bool is_white = false;
    std::cout << "taille data : "<<data.size() << std::endl;
    for(int pos=0; pos<(data.size()-2); pos++){
        if( (detect_white(pos) ^ is_white) ){
            compteur2++;
            taille.push_back(compteur);
            compteur=0;
            is_white = !(is_white);
        }
        else{
            compteur++;
        }
    }
    std::cout<< "taille compteur2 : "<<compteur2<<std::endl;
    taille.push_back(compteur);

    //donne blanc(0), ti(1), ta(2) ou /(3)
    //avec un niveau min ou au 0 deux fois d'affilée
} */

int main(){
    /* std::ofstream ecrire("./essai.txt", std::ofstream::binary);
    ecrire<<1000; */

    /* std::ifstream lire ("./essai.txt", std::ifstream::binary);
    std::cout << lire.is_open() << std::endl;
    char chunkid[4];
    int val;
    char vale;

    while( lire.get(vale) ){
        val = vale;
        std::cout << lire.tellg() << " ";
        std::cout << val << std::endl;
    } */
    /* for(int i = 0;i<4;i++){
        std::cout << lire.tellg() << " ";
        int val = lire.get();
        std::cout << val << std::endl;
    }
    lire.get(); */

    /* unsigned char lecture[4];
    int entier[4];
    int result=0;
    for(int i=0; i<4; i++){
        //lecture[i] = lire.get();
        //entier[i] = static_cast<int>(lecture[i]);
        entier[i] = lire.get();
        std::cout << lecture[i] << " "<< entier[i]  << std::endl;
    }
    result = ( (entier[1] << 8) | entier[0] );
    //result = swap(result, 4);
    std::cout << result << std::endl;


    int first = 0b00001000;
    int second = 0b00100100;
    std::cout << ((first << 8) | (second)) << std::endl;
    first = 8;
    second = 36;
    std::cout << ((first << 8) | (second)) << std::endl;
    first = entier[1];
    second = entier[0];
    std::cout << ((first << 8) | (second)) << std::endl; */
    double a = 0.99;
    int b = a;
    std::cout << b << std::endl;
    
    return 0;
}
