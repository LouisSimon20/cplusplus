/**
 * @file morsetowav.cpp
 * @author Louis SIMON
 * @brief Fichier contenant la classe Morse
 * @date 2021-01-24
 */

#include <vector>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

# define PI 3.141592 /* pi */

/**
 * @brief Classe permettant d'encoder le message morse(.--) en wav.
 * 
 */
class Morse{
    friend void encodage();
    friend void morse_construction();
    friend void morse_taille();

public:
    /**
     * @brief Construct a new Morse object
     * 
     * Initialisation des 3 sons du fichier wav (blanc, ti, taah)
     * @param morse message en morse
     */
    Morse(std::string morse):morse(morse)
    {
        double t;
        int ValPerSample = pow(2, BitsPerSample); //256 val possible
        int nbSampleTi = dureeTi*SampleRate;

        //BLANC
        blanc = std::string (dureeTi*SampleRate, static_cast<char>(0));
        //TI
        for(int i=0; i<nbSampleTi; i++){
            t=(double)i/SampleRate; // on convertit en temps
            char val = static_cast<char>( (sin(2 * PI * frequenceTi * t) + 1) * ValPerSample / 2) ;
            ti.push_back(val);
        }
        //TA
        if(frequenceTa == frequenceTi){
            for(int i=0; i<3;i++){
                ta.append(ti);
            }
        }
        else{
            for(int i=0; i<3*nbSampleTi; i++){
                t=(double)i/SampleRate; // on convertit en temps
                ta.push_back((sin(2 * PI * frequenceTa * t) + 1) * ValPerSample / 2);
            }
        }
    }
    /**
     * @brief Demande à l'utilisateur le chemin du fichier audio qu'il veut créer
     * 
     */
    void Acquire(){
        getline(std::cin, path);
    }
    /**
     * @brief Ecrit un entier en little endian sur n=taille bits.
     * 
     * @param octets L'entier à convertir
     * @param taille Le nombre de bits sur lequel l'écrire
     * @param fichier Le flux du fichier dans lequel l'écrire
     */
    void ecrire_little_endian(unsigned int octets, int taille, std::ofstream& fichier){
        unsigned char faible ;
        while(taille > 0) {   
            faible = octets & 0x000000FF ;
            fichier<<faible;
            octets = octets >> 8 ;
            taille = taille - 1 ;
        }
    }
    /**
     * @brief Calcule la taille du message en ti
     * 
     * Cette fonction permet d'écrire l'entête avant les données. \n
     * En effet, la taille du fichier est à spécifier dans l'entête. \n
     * La taille est calculée en ti : si le message est ".-", la taille sera de (1+1) + (3+1)
     * 
     * @return int - taille du message en ti
     */
    int tailleMessage(){
        //permet d'écrire l'entête avant les données
        int compteur = 0;
        for(int i=0; i<strlen(morse.c_str()); i++){
            switch(morse[i]){
                case '.' :  compteur=compteur+2;
                            break;
                case '-' :  compteur=compteur+4;
                            break;
                case ' ' :  compteur=compteur+2;
                            break;
                case '/' :  compteur=compteur+2;
                            break;
            }
        }
        return compteur;
    }
    /**
     * @brief Ecrit l'entête du fichier audio
     * 
     * @param fichier flux du fichier dans lequel écrire l'entête.
     */
    void ecrire_en_tete_WAV(std::ofstream& fichier) {
        //calcul autres données
        int taille = tailleMessage();
        long ByteRate = SampleRate*NumChannels*BitsPerSample/8;
        int BlockAlign = NumChannels*BitsPerSample/8;
        unsigned int nb_octets_donnees = SampleRate*(BitsPerSample/8)*NumChannels*1.1*dureeTi*taille;

        //Ecriture
        fichier<<"RIFF";
        ecrire_little_endian(36+nb_octets_donnees, 4, fichier);//?
        fichier<<"WAVEfmt ";
        ecrire_little_endian(16, 4, fichier);
        ecrire_little_endian(AudioFormat, 2, fichier);
        ecrire_little_endian(NumChannels, 2, fichier);
        ecrire_little_endian(SampleRate, 4, fichier);
        ecrire_little_endian(ByteRate, 4, fichier);
        ecrire_little_endian(BlockAlign, 2, fichier);
        ecrire_little_endian(BitsPerSample, 2, fichier);
        fichier<<"data";
        ecrire_little_endian(nb_octets_donnees, 4, fichier);
    }

    /**
     * @brief Ecrit les données du fichier audio
     * 
     * @param fichier flux du fichier dans lequel écrire les données
     */
    void ecrire_donnees(std::ofstream& fichier){
        for(int i=0; i<strlen(morse.c_str()); i++){
            switch(morse[i]){
                case '.' :  fichier<<ti;
                            fichier<<blanc;
                            break;
                case '-' :  fichier<<ta;
                            fichier<<blanc;
                            break;
                case ' ' :  fichier<<blanc;
                            fichier<<blanc;
                            break;
                case '/' :  fichier<<blanc;
                            fichier<<blanc;
                            break;
            }
        }
    }

    /**
     * @brief Crée le fichier audio
     * 
     * Cette fonction permet de laisser le choix à l'utilisateur de spécifier un chemin pour le fichier audio.
     */
    void translateMtoW(){
        if(path.size() != 0){
            std::ofstream fichierwav(path.c_str(), std::ofstream::binary);
            ecrire_en_tete_WAV(fichierwav);
            ecrire_donnees(fichierwav);
        }
        else{
            std::ofstream fichierwav("./CodeMorse.wav", std::ofstream::binary);
            ecrire_en_tete_WAV(fichierwav);
            ecrire_donnees(fichierwav);
        }
    }

private:
    std::string morse, path;
    std::string ti, ta, blanc;

    //Données modifiables
    int AudioFormat = 1; //PCM
    int NumChannels = 1; // 1 = mono
    int BitsPerSample = 8; // codé entre 0 et 255
    int SampleRate = 44100; //taux d'échantillonage (on peut mettre 8000)
    double dureeTi = 0.2; //TI dure 0.2 seconde
    int frequenceTa = 440; //La pur
    int frequenceTi = 1000;
};