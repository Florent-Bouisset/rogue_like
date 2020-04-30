#ifndef RELIQUE_H
#define RELIQUE_H


//=================================
// forward declared dependencies
class Champion;

//=================================
// included dependencies
#include <string>
#include <map>
#include "enum.h"

enum RelicType{ALTERE, ANANAS, JUS_CITRON, VIN_ROUGE, ARME_EMPOISONNEE};

class Relic{
    public:
        Relic();
        Relic(RelicType unType);
        void giveABoost(Champion& target);
        std::string getName();

    protected :
        //Methods
        void giveARandomType();
        void giveNameFromMap();
        void changeHP(Champion& target, int amount, ActionType action);
        void changeMaxHP(Champion& target, int amount, ActionType action);
        void changeDamage(Champion& target, int amount, ActionType action);

        //Attributes
        RelicType relicType;
        static std::map<RelicType, std::string> namesMap;
        std::string name;
};


#endif