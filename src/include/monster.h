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
        static std::map<MonsterType, Stats> predefinedStats;
        //METHODS
        void giveARandomType();
        void giveStatsFromMap();

    protected:
        //ATTRIBUTES
        Stats stats;
        int level;
        int goldReward;
        MonsterType monsterType;



};

#endif