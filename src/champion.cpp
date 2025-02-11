#include "include/champion.h"
#include "include/boss.h"
#include "include/relic.h"
#include "include/article.h"

#include <iostream>

using namespace std;

Champion::Champion() : Fighter("Geralt", 150, 150)
{
    damage = 20;
    gold = 25;
    illustrationPath = "image/fighter/champion/geralt.png";
}

void Champion::printInfos() const
{
    cout << getName() << " : " << getHP() << " HP " << getMaxHP() << " HP Max " << getDamage() << " Damage " << gold << " Gold " << endl;
}

/**
 * change l'or du champion
 * il n'y a pas de limite d'or
 * et il ne peut pas avoir moins de 0 Or
 *  */

void Champion::changeGold(const int goldAmount, const ActionType action)
{
    switch (action)
    {
    case ADDITION:
        gold += goldAmount;
        break;

    case SOUSTRACT:
        if (goldAmount > gold)
        {
            gold = 0;
            break;
        }
        else
        {
            gold = gold - goldAmount;
            break;
        }

    default:
        break;
    }
}

/**
 * permet au champion de combattre un monstre
 * le combat se fait en plusieurs round et s'arrete quand un des
 * deux combattant est mort
 *
 */

void Champion::fightForOneTurn(Monster &target)
{
    if (this->isAlive() && target.isAlive())
    {
        this->attack(target);
        target.attack(*this);
    }
}

/**
 * Prend les recompenses d'un monstre
 * donc augmente l'or du champion

 * Prends les recompenses d'un boss
 * cad les recompenses classique d'un combat normal
 * + une relic special
 * */

void Champion::takeRewards(shared_ptr<Monster> target)
{
    target->giveRewards(*this);
}

void Champion::buyArticle(Article &article)
{
    if (canAfford(article))
    {
        changeGold(article.getPrice(), ActionType::SOUSTRACT);
        article.getItem()->interact(*this);
    }
    else
    {
        cout << "Pas assez d'or pour acheter cet article" << endl;
    }
}

bool Champion::canAfford(const Article &article) const
{
    return (gold >= article.getPrice());
}

int Champion::getGold() const
{
    return gold;
}