#include "include/monster.h"

#include "include/champion.h"

using namespace std;

Monster::Monster()
{
}

int Monster::getGoldReward() const
{
    return goldReward;
}

void Monster::giveRewards(Champion &champion)
{
    champion.changeGold(this->getGoldReward(), ADDITION);
}