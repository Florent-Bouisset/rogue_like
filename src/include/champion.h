#ifndef PERSONNAGE_H
#define PERSONNAGE_H

//=================================
// forward declared dependencies
class Monster;
class Boss;
class Article;

//=================================
// included dependencies
#include "fighter.h"


class Champion : public Fighter{
    public:
        Champion(std::string name);
        void printInfos() const;
        void fightAMonster(Monster& target);
        void takeRewards(Monster& target);
        void takeRewards(Boss& target);
        void buyArticle(Article& article);
        bool canAfford(Article& article);
        void changeGold(const int goldAmount, const ActionType action);

    private:
        int gold;
        

};

#endif