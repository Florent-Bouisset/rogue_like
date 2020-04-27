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
        Champion(std::string nom);
        void afficheInfos();
        void changeOr(int montantOr, ActionType action);
        void fightAMonster(Monster& target);
        void fightABoss(Boss& target);
        void prendreRecompense(Monster& target);
        void prendreRecompense(Boss& target);


    private:
        
        int gold;
        //std::vector<Relic> relics;

};

#endif