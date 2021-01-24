/**
 * @file wavtomorse.cpp
 * @author Louis SIMON (you@domain.com)
 * @brief Fichier contenant la classe Wav
 * @date 2021-01-23
 */

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include "math.h"

/**
 * @brief Classe permettant d'extraire les données d'un fichier wav et de 
 *        les transformer en morse (.--)
 * 
 */
class Wav{
    friend void decodage();
public:
    /**
     * @brief Construct a new Wav object
     * 
     * @param chemin : chemin de fichier audio à décoder
     */
    Wav(std::string chemin):chemin(chemin) {
        pfile = new std::ifstream(chemin.c_str(), std::ifstream::binary);
    }
    /**
     * @brief Lit n=taille bits et convertit de little a big endian
     * 
     * @param taille nombre de bits à lire dans le fichier
     * @param fichier flux d'entrée concernant le fichier son
     * @return un entier correspondant à la valeur des bits lus 
     */
    int lire_wav(int taille, std::ifstream& fichier){
        int lecture[taille];
        int res=0;
        for(int i=0; i<taille; i++){
            lecture[i] = fichier.get();
            res = (lecture[i] << 8*i) | res;
        }
        return res;
    }

    /**
     * @brief Stocke toutes les données contenues dans l'entête d'un fichier wav
     * 
     */
    void acq_entete(){
        //ChunkID (= RIFF)
        (*pfile).read(ChunkID, 4);
        
        //ChunkSize
        ChunkSize = lire_wav(4, (*pfile));

        //Format (= WAVE)
        (*pfile).read(Format, 4);

        //SubChunk1ID (= fmt_)
        (*pfile).read(Subchunk1ID, 4);

        //Subchunk1Size
        Subchunk1Size = lire_wav(4, (*pfile));
        
        //AudioFormat
        AudioFormat = lire_wav(2, (*pfile));

        //NumChannels
        NumChannels = lire_wav(2, (*pfile));

        //SampleRate
        SampleRate = lire_wav(4, (*pfile));

        //ByteRate
        ByteRate = lire_wav(4, (*pfile));

        //BlockAlign
        BlockAlign = lire_wav(2, (*pfile));

        //BitsPerSample
        BitsPerSample = lire_wav(2, (*pfile));

        //Subchunk2ID
        (*pfile).read(Subchunk2ID, 4);

        //Subchunk2Size
        Subchunk2Size = lire_wav(4, (*pfile));
    }
    /**
     * @brief Vérifie que le fichier est bien un fichier wav
     * 
     * @return true - le fichier a un entête correcte
     * @return false - le fichier n'a pas un entête correcte
     */
    bool verif_entete(){
        bool flag=true;
        flag = ((ChunkID[0] == 'R') & (ChunkID[1] == 'I') & (ChunkID[2] == 'F') & (ChunkID[3] == 'F'));
        flag = flag & ((Format[0] == 'W') & (Format[1] == 'A') & (Format[2] == 'V') & (Format[3] == 'E'));
        flag = flag & ((Subchunk1ID[0] == 'f') & (Subchunk1ID[1] == 'm') & (Subchunk1ID[2] == 't') & (Subchunk1ID[3] == ' '));
        flag = flag & ((Subchunk2ID[0] == 'd') & (Subchunk2ID[1] == 'a') & (Subchunk2ID[2] == 't') & (Subchunk2ID[3] == 'a'));
        //on pourrait également vérifier la correspondance entre les valeurs comme BlockAlign
        
        return flag;
    }
    /**
     * @brief Les données sont stockées dans le vecteur data
     *        valeurs entre 0 et 1
     * 
     */
    void acq_data(){
        int valeur, i=0;

        while(!(*pfile).eof()){
            valeur = (*pfile).get();
            data.push_back( (double)valeur/(pow(2, BitsPerSample))); 
            i++;
        }
        data.pop_back();
    }
    /**
     * @brief Decoupe le vecteur de données data
     *        Le principe est d'utiliser la taille standardisée des symboles morses
     *        Un ti sera de taille 1, un taah de taille 3 et un grand espace ( / ) de taille 7
     *        Pour différencier les blancs des symboles on utilise un deuxième vecteur
     * 
     */
    void decoupage(){
        int compteur=0;
        bool is_white = false;
        
        for(int pos=0; pos<(data.size()-4); pos++){
            if( (detect_white(pos) ^ is_white) ){
                taille.push_back((double)compteur/SampleRate/0.2);
                blanc.push_back(is_white);
                compteur=0;
                is_white = !(is_white);
            }
            else{
                compteur++;
            }
        }
        double min = *std::min_element(taille.begin(), taille.end());   //Permet de trouver la taille d'un TI
        std::transform(taille.begin(), taille.end(), taille.begin(), [&min](auto& c){return floor((c/min)+0.5);});  //pour avoir un tableau de valeur entières
    }

    /**
     * @brief utilisé dans la fonction decoupage()
     * 
     * Permet de détecter le passage d'un symbole (ti ou taah) à un blanc \n
     * 4 zeros consécutifs dans un symbole est un phénomène extrêmement rare :
     * il caractérise donc le passage d'un symbole à un blanc.
     * 
     * @param pos itérateur du vecteur data
     * @return true - On vient de passer à un blanc
     * @return false - On est dans un symbole
     */
    bool detect_white(int pos){
        return ( (data[pos] == 0) & (data.at(pos+1) == 0) & (data.at(pos+2) == 0) & (data.at(pos+3) == 0) & (data.at(pos+4) == 0));
    }
    /**
     * @brief Convertit les deux tableaux en langage morse
     * 
     */
    void translatemorse(){
        for(int i=0; i<taille.size();i++){
            if( (taille[i] == 1) & ~blanc[i] ){
                morse.push_back('.');
            }
            else if( ( (taille[i] == 3) or (taille[i] == 2) ) & blanc[i] ){
                morse.push_back(' ');
            }
            else if( (taille[i] == 3) & ~blanc[i] ){
                morse.push_back('-');
            }
            else if( (taille[i] == 7) or (taille[i] == 7)){
                morse.append(" / ");
            }
        } 
    }

private:
    char ChunkID[4], Format[4], Subchunk1ID[4], Subchunk2ID[4];
    int ByteRate, BlockAlign;
    int ChunkSize, Subchunk1Size, Subchunk2Size;
    int AudioFormat;
    int NumChannels;
    int BitsPerSample;
    int SampleRate;

    std::string chemin, morse;
    std::ifstream* pfile;
    std::vector<double> data, taille;
    std::vector<bool> blanc;
};