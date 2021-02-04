#include "graph.h"
#define PI 3.141592 /* pi */

//FORME
Forme::Forme(int x, int y):x(x), y(y) {}

std::vector<int> Forme::move(int xp, int yp){
    x=xp;
    y=yp;
    std::vector<int> c = {x, y};
    return c;
}

//CERCLE
Cercle::Cercle(int x, int y,int rayon): Forme(x, y), rayon(rayon) {}

double Cercle::area(){
    return PI*rayon*rayon;
}

//CARRE
Carre::Carre(int x, int y, int cote) : Forme(x, y), cote(cote) {}
        
double Carre::area(){
    return cote*cote;
}