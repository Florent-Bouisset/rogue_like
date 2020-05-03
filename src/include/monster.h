#ifndef MONSTRE_H
#define MONSTRE_H

class Champion;

#include "fighter.h"

class Monster : public Fighter
{
public:
    Monster();

    //GETTERS
    int getGoldReward() const;
    virtual void giveRewards(Champion &champion);

private:
    //METHODS
    friend class MonsterCreator;

protected:
    //ATTRIBUTES
    int level;
    int goldReward;
};

#endif