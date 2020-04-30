#ifndef MONSTRE_H
#define MONSTRE_H

#include "fighter.h"

class Monster : public Fighter{
    public:
        Monster();

        //GETTERS
        int getGoldReward();

    private:
        //METHODS
        friend class MonsterCreator;


    protected:
        //ATTRIBUTES
        int level;
        int goldReward;

};

#endif