#ifndef RELIQUE_H
#define RELIQUE_H

#include "enum.h"
class Champion;

class Relic{
    public:
        Relic();
        Relic(RelicType unType);
        void changeHP(Champion& target, int amount, ActionType action);
        void changeMaxHP(Champion& target, int amount, ActionType action);
        void changeDamage(Champion& target, int amount, ActionType action);
        void giveABoost(Champion& target);

    private :
        RelicType typeRelic;
};





#endif