#include <math.h>
#include <iostream>
#include <vector>
# define PI 3.141592 /* pi */

int main()
{
    double frequence = 2;
    double t;
    double signal = sin(2 * PI * frequence * t);

    int BitsPerSample = 8; // a ajouter
    int ValPerSample = pow(2, BitsPerSample);
    int val = (signal + 1) * ValPerSample / 2;
    int i=0;

    // NB ECHANTILLONS
    int SampleRate = 10;
    int duree = 3; //le signal dure 3 sec
    int nbSample = duree*SampleRate;
    std::vector <char> vec(nbSample);//ne pas oublier de changer le type si on veut changer le type


    for(int i=0; i<nbSample; i++){
        t=(double)i/SampleRate; // on convertit en temps
        double hello = 2 * PI * frequence * t;
        signal = sin(hello);
        int val = (signal + 1) * ValPerSample / 2;
        vec[i] = (sin(2 * PI * frequence * t) + 1) * ValPerSample / 2;
        std::cout << signal << " " << vec[i] << " " << std::endl;
    }
    for (int i=0; i<nbSample; i++){
        std::cout << vec[i] << " " << std::endl;
    }

    /* while(frequence * t < 1)
    {
        t = (double)i/20;
        double hello = 2 * PI * frequence * t;
        signal = sin(hello);
        val = (signal + 1) * ValPerSample / 2;
        std::cout << hello<< " " << signal << " " << << " " << val<< std::endl;
        i++;
    } */
}
