#ifndef RELIQUE_H
#define RELIQUE_H

#include "enum.h"
class Champion;


class Relic{
    public:
        Relic();
        Relic(TypeRelic unType);
        void changeHP(Champion& cible, int quantite, typeAction action);
        void changeHPMax(Champion& cible, int quantite, typeAction action);
        void changeDegats(Champion& cible, int quantite, typeAction action);
        void donnerBoost(Champion& cible);

    private :
        TypeRelic typeRelic;
};





#endif