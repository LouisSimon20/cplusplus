/**
 * @file morsetofr.cpp
 * @author Louis SIMON
 * @brief Fichier contenant les classes Arbre et Noeud
 * @date 2021-01-24
 */

#include <string>
#include <cstring>
#include <iostream>

/**
 * @brief Classe d'un noeud de l'arbre
 * 
 */
class Noeud{
    friend class Arbre;
public:
    /**
     * @brief Construct a new Noeud object
     * 
     * @param cara le caractère du noeud
     * @param LienBarre le lien vers le noeud suivant la branche barre(le prochain caractère est une barre).
     * @param LienPoint le lien vers le noeud suivant la branche point.
     */
    Noeud(char cara, Noeud* LienBarre, Noeud* LienPoint):cara(cara), LienBarre(LienBarre), LienPoint(LienPoint){}
    /**
     * @brief Construct a new Noeud object
     * 
     * Les liens sont initialisés à nullptr : on a atteint la fin de la branche
     * @param cara le caractère du noeud
     */
    Noeud(char cara): cara(cara), LienBarre(nullptr), LienPoint(nullptr){}

private:
    char cara;
    Noeud* LienBarre;
    Noeud* LienPoint;
};

/**
 * @brief Classe définissant un arbre binaire permettant de passer du morse (.--) au francais.
 * 
 * Cette arbre permet de traduire le morse vers le francais. \n
 * L'arbre se base sur celui présent sur le site : https://radiobxi.org/blog/graphique-de-decodage-du-code-morse/
 * 
 */
class Arbre{
    friend void decodage();
public:
    /**
     * @brief Construct a new Arbre object
     * 
     * @param morse message en morse
     */
    Arbre(std::string morse):morse(morse){
        pnj = new Noeud('j');
        pnp = new Noeud('p');
            pnw = new Noeud('w', pnj, pnp);
        pnl = new Noeud('l');   
            pnr = new Noeud('r', nullptr, pnl);
                pna = new Noeud('a', pnw, pnr);
        pnf = new Noeud('f');
            pnu = new Noeud('u', nullptr, pnf);
        pnv = new Noeud('v');
        pnh = new Noeud('h');
            pns = new Noeud('s', pnv, pnh);
                pni = new Noeud('i', pnu, pns);
                    pne = new Noeud('e',pna, pni);

        pnx = new Noeud('x');
        pnb = new Noeud('b');
            pnd = new Noeud('d', pnx, pnb);
        pnc = new Noeud('c');
        pny = new Noeud('y');
            pnk = new Noeud('k', pny, pnc);
                pnn = new Noeud('n', pnk, pnd);
            pno = new Noeud('o');
        pnq = new Noeud('q');
        pnz = new Noeud('z');
            png = new Noeud('g', pnq, pnz);
                pnm = new Noeud('m', pno, png);
                    pnt = new Noeud('t', pnm, pnn);
        base = new Noeud('\0', pnt, pne);
    }
    /**
     * @brief Destroy the Arbre object
     * 
     */
    ~Arbre(){
        delete pna;
        delete pnb;
        delete pnc;
        delete pnd;
        delete pne;
        delete pnf;
        delete png;
        delete pnh;
        delete pni;
        delete pnj;
        delete pnk;
        delete pnl;
        delete pnm;
        delete pnn;
        delete pno;
        delete pnp;
        delete pnq;
        delete pnr;
        delete pns;
        delete pnt;
        delete pnu;
        delete pnv;
        delete pnw;
        delete pnx;
        delete pny;
        delete pnz;
        delete base;
    }

    /**
     * @brief Traduit le morse en francais
     * 
     * Navigue dans l'arbre pour traduire le message
     * 
     */
    void morsetofr(){
        Noeud ncourant = *base;
        int size_morse = strlen(morse.c_str());
        for(int i=0; i<size_morse;i++){
            switch (morse[i]){
                case '.':
                    ncourant = *(ncourant.LienPoint);
                    break;
                
                case '-':
                    ncourant = *(ncourant.LienBarre);
                    break;

                case ' ':
                    fr.push_back(ncourant.cara);
                    if(i != (size_morse-1) ){
                        if(morse[i+1] == '/'){
                            fr.push_back(' ');
                            i++;
                        }
                    }
                    ncourant = *base;
                    break;
                
                default:
                    std::cout << "erreur" << std::endl;
                    break;
            }
        }
        if (ncourant.cara != '\0'){
            fr.push_back(ncourant.cara);
        }
    }
private:
    std::string morse, fr;
    Noeud* base;
    Noeud *pna, *pnb, *pnc, *pnd, *pne, *pnf, *png, *pnh, *pni, *pnj, *pnk;
    Noeud *pnl, *pnm, *pnn, *pno, *pnp, *pnq, *pnr, *pns, *pnt, *pnu, *pnv;
    Noeud *pnw, *pnx, *pny, *pnz;
};