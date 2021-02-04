#include <fstream>

/* void ecrire_little_endian(int valeur, int taille, std::ofstream& fichier){
    if(taille==2){
        unsigned char little = (valeur>>8) | (valeur<<8);
        fichier<<little;
    }
    else if(taille==4){
        unsigned char little = ((valeur>>24)&0xff) | ((valeur<<8)&0xff0000) | ((valeur>>8)&0xff00) | ((valeur<<24)&0xff000000);
        fichier<<little;
    }
} */

void ecrire_little_endian(unsigned int octets, int taille, std::ofstream& fichier) {
    unsigned char faible ;
    
    while(taille > 0) {   
        faible = octets & 0x000000FF ;
        fichier<<faible;
        octets = octets >> 8 ;
        taille = taille - 1 ;
    }
}

void ecrire_en_tete_WAV(std::ofstream& fichier) { //plus que la taille a renseigner

    //Données à modifier
    int AudioFormat = 1; //PCM
    int NumChannels = 1; // 1 = mono
    int BitsPerSample = 8; // codé entre 0 et 255
    int SampleRate = 44100; //taux d'échantillonage (on peut mettre 8000)

    //autre données
    long ByteRate = SampleRate*NumChannels*BitsPerSample/8;
    int BlockAlign = NumChannels*BitsPerSample/8;

    int duree = 3 ;//dépend du message ca
    int size =SampleRate*duree;//? le nb d'échantillon
    unsigned int nb_octets_donnees = (BitsPerSample/8)*NumChannels*size;//? Il faut le nombre d'échantillon

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

/* int main(){
    std::ofstream wav("entete.txt", std::ofstream::binary);
    ecrire_en_tete_WAV(wav);
} */