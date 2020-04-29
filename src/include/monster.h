#ifndef MONSTRE_H
#define MONSTRE_H

#include <map>
#include <string>
#include "fighter.h"
#include "stats.h"

class Monster : public Fighter{
    public:
        Monster();

        //GETTERS
        int getGoldReward();

    private:

        //METHODS
        void giveARandomType();
        void giveStatsFromMap();

        //ATTRIBUTES
        Stats stats;
        int level;
        int goldReward;
        MonsterType monsterType;
        static std::map<MonsterType, Stats> predefinedStats;


};

#endif