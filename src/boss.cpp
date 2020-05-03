#include "include/boss.h"

using namespace std;

Boss::Boss()
{
}

Relic Boss::getRelicReward() const
{
    return relicReward;
}

void Boss::giveRewards(Champion &champion)
{
    Monster::giveRewards(champion);
    relicReward.giveABoost(champion);
}
