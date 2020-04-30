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
        std::string getName() const;

    protected :
        //Methods
        void giveARandomType();
        void giveNameFromMap();
        void changeHP(Champion& target, const int amount, const ActionType action);
        void changeMaxHP(Champion& target, const int amount, const ActionType action);
        void changeDamage(Champion& target, const int amount, const ActionType action);

        //Attributes
        RelicType relicType;
        static std::map<RelicType, std::string> namesMap;
        std::string name;
};


#endif