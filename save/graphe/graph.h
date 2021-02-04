#include <iostream>
#include <vector>

class Forme{
    public:
        std::vector<int> move(int xp, int yp);
        virtual double area()=0;
    private:
        int x;
        int y;
    protected:
        Forme(int x, int y);
};

class Cercle : public Forme{
    public:
        Cercle(int x, int y,int rayon);
        double area();
    private:
        int rayon;
};

class Carre : public Forme{
    public:
        Carre(int x, int y, int cote);
        double area();
    private:
        int cote;
};