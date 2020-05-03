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

class Champion : public Fighter
{
public:
    Champion();
    void printInfos() const;
    void fightAMonster(Monster &target);
    void fightForOneTurn(Monster &target);
    void takeRewards(Monster *target);
    void buyArticle(Article &article);
    bool canAfford(const Article &article) const;
    void changeGold(const int goldAmount, const ActionType action);
    int getGold() const;

protected:
    int gold;
};

#endif