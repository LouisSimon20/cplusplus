#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include "math.h"

int stringToInt(std::string str){
    int taille=strlen(str.c_str());
    std::cout << " taile : " << taille << std::endl;
    int res=0;
    for(int i=0; i<taille; i++){
        int st = static_cast<int>(static_cast<unsigned char>(str[i]));
        std::cout << "str i :" << str[i] << " st : " << st << std::endl;
        res = res + st*pow(10,taille-i-1);
    }
    return res;
}


class Wav{
public:
    Wav(std::string chemin):chemin(chemin) {
        std::string ligne;
        while(getline(fichierwav, ligne)){
            wav.append(ligne);
        }
    }

    int lire_wav(int taille, std::ifstream& fichier){
        int lecture[taille];
        int res=0;
        for(int i=0; i<taille; i++){
            lecture[i] = fichier.get();
            res = (lecture[i] << 8*i) | res;
            std::cout << lecture[i] << std::endl;
        }
        return res;
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
            res = ((octets >> 8) & 0x00FF) | ((octets << 8) & 0xFF00);
        }
        
        return res;
    }

    void entete(){
        int faible;

        //ChunkID = RIFF
        ChunkID = wav.substr(0, 4);
        std::cout << ChunkID << std::endl;

        //ChunkSize
        faible = std::stoi(wav.substr(4, 4));
        ChunkSize = swap(faible, 4);
        std::cout << faible << " " <<ChunkSize << std::endl;

        //Format = WAVE
        Format = wav.substr(8, 4);
        std::cout << Format << std::endl;

        //SubChunk1ID = fmt_
        Subchunk1ID = wav.substr(12, 4);
        std::cout  << Subchunk1ID << std::endl;

        //Subchunk1Size
        faible = stringToInt(wav.substr(16, 4));
        //Subchunk1Size = swap(faible, 4);
        std::cout << faible << std::endl;

        //AudioFormat
        faible = stringToInt(wav.substr(20, 2));
        std::cout << faible << std::endl;

        //AudioFormat
        faible = stringToInt(wav.substr(22, 2));
        std::cout << faible << std::endl;

        //AudioFormat
        faible = stringToInt(wav.substr(24, 4));
        std::cout << faible << std::endl;

        //SampleRate
        faible = std::stol(wav.substr(24, 4));
        std::cout << swap(faible, 4) << std::endl;
        std::cout << wav.substr(24, 4) << std::endl;
        std::cout << std::stol(wav.substr(24, 4)) << std::endl;
        
        
        for(int i=0; i<500; i++){
            std::cout << wav[i] << std::endl;
        }

    }

//private:
    std::string ChunkID, Format, Subchunk1ID, Subchunk2ID;
    int ChunkSize, Subchunk1Size;
    int AudioFormat; //PCM
    int NumChannels; // 1 = mono
    int BitsPerSample; // codé entre 0 et 255
    int SampleRate; //taux d'échantillonage (on peut mettre 8000)

    std::string chemin;
    std::string wav;
};

int main(){
    Wav wave();
    wave.entete();
}