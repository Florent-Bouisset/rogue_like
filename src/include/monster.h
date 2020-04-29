#ifndef MONSTRE_H
#define MONSTRE_H

#include <map>
#include <string>
#include "fighter.h"

class Monster : public Fighter{
    public:
        Monster();
        int getGoldReward();

    private:
        void giveARandomType();
        void giveANameFromMap();
        int level;
        int goldReward;
        MonsterType monsterType;
        static std::map<MonsterType, std::string> names;


};

#endif