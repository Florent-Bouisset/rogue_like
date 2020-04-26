#ifndef UNITE
#define UNITE

#include <string>

class Unite{
    public:
        Unite();
        Unite(std::string, int, int);
        void gagnerPV(int nbPV);
        void perdrePV(int nbPV);
        void gagnerPVMax(int nbPVMax);
        void perdrePVMax(int nbPVMax);
        void attaquer(Unite& cible);
        bool estVivant();
        void afficheVie();

        //getter
        int getPVMax();
        int getPV();
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