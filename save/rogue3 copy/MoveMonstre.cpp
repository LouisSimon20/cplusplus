#include "pers.h"
#include "objet.cpp"
#include <vector>
#include <iostream>

std::vector<Objet> ListeObjet;
ListeObjet.push_back( PetitePiece(std::make_pair(1, 1)) );
ListeObjet.push_back( GrandePiece(std::make_pair(2, 2)) );

void Deplacement(Hero* H){
    int xheros = (*H).getpos().first;
    int yheros = (*H).getpos().second;
    dx = xheros - coord.first();
    dy = yheros - coord.second();
    if( (abs(dx) <5) or (abs(dy)< 5)){
        if( abs(dx) >= abs(dy) ){ //on se deplace selon x
            if( dx > 0){
                move(1, 0);
            }
            else{
                move(-1, 0);
            }
        }
        else{
            if( dy > 0){
                move(0, 1);
            }
            else{
                move(0, -1);
            }
        }
    }
}

//fonction move du heros avec les murs

board board_basic;
bool move (int x0,int y0){
            if( ( board_basic.boardgame[std::make_pair(coord.first+x0, coord.second+y0)] == 0 ) or (board_basic.boardgame[std::make_pair(coord.first+x0, coord.second+y0)] == 1)){
                //c'est un mur
                return false;
            }
            
            else{
                coord.first+=x0;
                coord.second+=y0;
                return true;
            }
        } // Change la position, à utiliser surement avec des + ou -1 seulement pour éviter des téléportations
