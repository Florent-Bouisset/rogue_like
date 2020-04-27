#ifndef RELIQUE_H
#define RELIQUE_H


class Personnage;
#include "personnage.h"

class Relique{
    public:
        Relique();
        Relique(TypeRelique unType);
        void modifierPV(Personnage& cible, int quantite, typeAction action);
        void modifierPVMax(Personnage& cible, int quantite, typeAction action);
        void modifierDegats(Personnage& cible, int quantite, typeAction action);
        void donnerBoost(Personnage& cible);

    private :
        TypeRelique typeRelique;
};





#endif