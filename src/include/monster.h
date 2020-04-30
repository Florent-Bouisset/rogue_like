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
        friend class MonsterCreator;


    protected:
        //ATTRIBUTES
        Stats stats;
        int level;
        int goldReward;



};

#endif