#ifndef RELIQUE_H
#define RELIQUE_H


//=================================
// forward declared dependencies
class Champion;

//=================================
// included dependencies
#include <string>
#include "enum.h"


class Relic{
    public:
        Relic();
        Relic(RelicType unType);
        void giveABoost(Champion& target);
        std::string getName();

    private :
        void giveARandomType();
        void giveAName();
        void changeHP(Champion& target, int amount, ActionType action);
        void changeMaxHP(Champion& target, int amount, ActionType action);
        void changeDamage(Champion& target, int amount, ActionType action);
        RelicType relicType;
        std::string name;
};


#endif