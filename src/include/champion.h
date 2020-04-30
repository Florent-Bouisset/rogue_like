#ifndef PERSONNAGE_H
#define PERSONNAGE_H



//=================================
// forward declared dependencies
class Monster;
class Boss;


//=================================
// included dependencies
#include <vector>
#include <string>
#include "fighter.h"


class Champion : public Fighter{
    public:
        Champion(std::string name);
        void printInfos() const;
        void changeGold(const int goldAmount, const ActionType action);
        void fightAMonster(Monster& target);
        void fightABoss(Boss& target);
        void takeRewards(Monster& target);
        void takeRewards(Boss& target);


    private:

        int gold;
        //std::vector<Relic> relics;

};

#endif