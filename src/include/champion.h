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
#include <memory>

class Champion : public Fighter
{
public:
    Champion();
    void printInfos() const;
    void fightForOneTurn(Monster &target);
    void takeRewards(std::shared_ptr<Monster> target);
    void buyArticle(Article &article);
    bool canAfford(const Article &article) const;
    void changeGold(const int goldAmount, const ActionType action);
    int getGold() const;

protected:
    int gold;
};

#endif