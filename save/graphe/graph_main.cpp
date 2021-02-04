#include "graph.h"

int main(){
    Carre carre(0, 0, 2);
    int aireCarre = carre.area();
    std::cout << "Aire carre : " << aireCarre << std::endl;

    Cercle cercle(0, 0, 2);
    double aireCercle = cercle.area();
    std::cout << "Aire cercle : " << aireCercle << std::endl;

    std::vector<int> vec = cercle.move(1, 1);
    std::cout << vec[0] << " " << vec[1] << std::endl;

    std::vector<Cercle> VecCercle;
    VecCercle.push_back(cercle);
    std::vector<Forme*> VecForme;
    VecForme.push_back(&cercle);
    VecForme.push_back(&carre);
    VecForme[0]->move(5, 5);
    double aire = VecForme[1]->area();
    std::cout << aire << std::endl;
    return 0;
}