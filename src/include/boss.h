#ifndef BOSS_H
#define BOSS_H

#include "monster.h"
#include "enum.h"
#include "relic.h"
#include "stats.h"

class Boss : public Monster{
    public:
        //CONSTRUCTORS
        Boss();

        //GETTERS
        Relic getRelicReward();

    protected:
        //METHODS
        void giveARandomType();
        void giveStatsFromMap();

        //ATTRIBUTES
        BossType bossType;
        Relic relicReward;
        static std::map<BossType, StatsBoss> predefinedStats;
};

#endif