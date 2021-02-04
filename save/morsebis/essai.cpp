 #include <iostream>
 #include <string>

unsigned char ecrire_little_endian(unsigned int octets, int taille){

    unsigned char faible ;
            
    while(taille > 0) {   
        faible = octets & 0x000000FF ;
        octets = octets >> 8 ;
        taille = taille - 1 ;
        std::cout << "a" << faible <<std::endl;
    }
    return faible;
}

void ecrire_big_endian(unsigned int octets, int taille){
    unsigned char gros;
    int big;
    while(taille > 0){
        gros = octets & 0x000000FF ;
        octets = octets >> 8 ;
        taille = taille - 1 ;

    }
}

long long swap(long long octets, long long taille){
    int b0, b1, b2, b3;
    long long res;
    if (taille==4){
        b0 = (octets & 0x000000ff) << 24u;
        b1 = (octets & 0x0000ff00) << 8u;
        b2 = (octets & 0x00ff0000) >> 8u;
        b3 = (octets & 0xff000000) >> 24u;
        res = b0 | b1 | b2 | b3;
    }

    if (taille==2){
       res = ((octets >> 8) & 0x00FF) | ((octets << 8) & 0xFF00);
    }
    
    return res;
}

int main(){

    long  octet = 10000000;
    octet = swap(octet, 4);
    std::cout << octet << std::endl;
    octet = swap(octet, 4);
    std::cout << octet << std::endl;

    octet = swap(octet, 2);
    std::cout << octet << std::endl;
    octet = swap(octet, 2);
    std::cout << octet << std::endl;

    std::cout << std::stol("10000000") << std::endl;
}
