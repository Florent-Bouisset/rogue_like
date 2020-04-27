#ifndef MONSTRE_H
#define MONSTRE_H


#include "fighter.h"

class Monster : public Fighter{
    public:
        Monster();
        int getGainOr();
        
    private:
        void GiveARandomType();
        void GiveAName();
        int level;
        int gainOr;
        MonsterType typeMonster;



};

#endif