#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <vector>
#include <string>
#include "fighter.h"
#include "monster.h"
#include "relic.h"
#include "boss.h"

class Champion : public Fighter{
    public:
        Champion(std::string name);
        void printInfos();
        void changeGold(int goldAmount, ActionType action);
        void fightAMonster(Monster& target);
        void fightABoss(Boss& target);
        void takeRewards(Monster& target);
        void takeRewards(Boss& target);


    private:
        
        int gold;
        //std::vector<Relic> relics;

};

#endif