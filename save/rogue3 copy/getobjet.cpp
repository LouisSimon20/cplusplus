#include "pers.h"
#include "objet.cpp"
#include <vector>
#include <iostream>

void TestObjet(){
    //for(int i=0; i<ListeObjet.size();i++){
    std::vector<Objet> ListeObjet;
    ListeObjet.push_back( PetitePiece(std::make_pair(1, 1)) );
    ListeObjet.push_back( PetitePiece(std::make_pair(2, 2)) );
    Hero Heros(1,1);

    /* int xobjet = ListeObjet[0].GetPos().first;
    int yobjet = ListeObjet[0].GetPos().second;
    int xheros = Heros.getpos().first;
    int yheros = Heros.getpos().second; */
    if( (xobjet == xheros) & (yobjet == yheros) ){
        std::cout << "slt" << std::endl; //Heros.Get(ListeObjet[i]);
    }
}
int main(){
    //vector<enemy> ListeMonstre;


    
    TestObjet();
    return 0;
}
