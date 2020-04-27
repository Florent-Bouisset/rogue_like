#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <vector>
#include <string>
#include "unite.h"
#include "monster.h"
#include "relic.h"
#include "boss.h"

class Champion : public Unite{
    public:
        Champion(std::string nom);
        void afficheInfos();
        void changeOr(int montantOr, typeAction action);
        void fightAMonster(Monster& cible);
        void fightABoss(Boss& cible);
        void prendreRecompense(Monster& cible);
        void prendreRecompense(Boss& cible);


    private:
        
        int gold;
        //std::vector<Relic> relics;

};

#endif