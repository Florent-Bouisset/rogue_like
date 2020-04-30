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

        //ATTRIBUTES
        Relic relicReward;

    private:
        friend class BossCreator;
};

#endif