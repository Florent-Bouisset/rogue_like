#ifndef UNITE_H
#define UNITE_H

#include "enum.h"
#include <string>

class Unite{
    public:
        Unite();
        Unite(std::string, int, int);
        void modifierPV(int nbPV, typeAction);
        void modifierPVMax(int nbPVMax, typeAction);
        void modifierDegats(int nbDegats, typeAction);
        void attaquer(Unite& cible);
        bool estVivant();
        void afficheVie();

        //getter
        int getPVMax();
        int getPV();
        int getDegats();
        std::string getNom();

        //setter
        void setNom(std::string);

    private:
        std::string nom;
        int PVMax;
        int PV;
        int degats;
};

#endif