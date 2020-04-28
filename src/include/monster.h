#ifndef MONSTRE_H
#define MONSTRE_H


#include "fighter.h"

class Monster : public Fighter{
    public:
        Monster();
        int getGoldReward();
        
    private:
        void giveARandomType();
        void giveAName();
        int level;
        int goldReward;
        MonsterType typeMonster;



};

#endif