#ifndef STATS_H
#define STATS_H

#include <string>
#include "stats.h"

struct Stats
{
    public:
        std::string name;
        int damage;
        int HP;
        int maxHP;
        int goldReward;
};

#endif