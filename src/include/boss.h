#ifndef BOSS_H
#define BOSS_H

class Champion;

#include "monster.h"
#include "relic.h"

class Boss : public Monster
{
public:
    //CONSTRUCTORS
    Boss();

    //GETTERS
    Relic getRelicReward() const;
    void giveRewards(Champion &champion);

protected:
    //ATTRIBUTES
    Relic relicReward;

private:
    friend class BossCreator;
};

#endif