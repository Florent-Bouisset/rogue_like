#ifndef RELIQUE_H
#define RELIQUE_H


class Personnage;
#include "personnage.h"

class Relique{
    public:
        Relique();
        void modifierPV(Personnage& Cible, int quantite, typeAction action);
        void modifierPVMax(Personnage& Cible, int quantite, typeAction action);
        void modifierDegats(Personnage& Cible, int quantite, typeAction action);

    private :
};





#endif