#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "entete.h"
# define PI 3.141592 /* pi */

std::vector<char> sinus(std::ofstream& fichier, int frequence, int BitsPerSample, int SampleRate, int duree){
    double t;
    double signal = sin(2 * PI * frequence * t);
    int ValPerSample = pow(2, BitsPerSample);
    int val = (signal + 1) * ValPerSample / 2;

    // NB ECHANTILLONS
    int nbSample = duree*SampleRate;
    std::vector <char> vec(nbSample);//ne pas oublier de changer le type si on veut changer le type

    for(int i=0; i<nbSample; i++){
        t=(double)i/SampleRate; // on convertit en temps
        vec[i] = (sin(2 * PI * frequence * t) + 1) * ValPerSample / 2;
        fichier<<vec[i];
    }
    return vec;
}

int main(){
    std::ofstream wav("essai.wav", std::ofstream::binary);
    ecrire_en_tete_WAV(wav);
    int frequence = 440;
    std::vector<char> data;
    data = sinus(wav, frequence, 8, 44100, 3);
    return 0;
}