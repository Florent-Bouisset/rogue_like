#ifndef UNITE_H
#define UNITE_H

#include "enum.h"
#include <string>

class Unite{
    public:
        Unite();
        Unite(std::string, int, int);
        void changeHP(int nbHP, typeAction);
        void changeHPMax(int nbHPMax, typeAction);
        void changeDegats(int nbDegats, typeAction);
        void attaquer(Unite& cible);
        bool estVivant();
        void afficheVie();

        //getter
        int getHPMax();
        int getHP();
        int getDegats();
        std::string getNom();

        //setter
        void setNom(std::string);

    private:
        std::string nom;
        int HPMax;
        int HP;
        int degats;
};

#endif