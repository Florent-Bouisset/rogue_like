#ifndef STATS_H
#define STATS_H

#include <string>
#include "stats.h"
#include "enum.h"

struct Stats
{
    public:
        std::string name;
        int damage;
        int HP;
        int maxHP;
        int goldReward;
};

/* en theorie il faudrait faire l'heritage mais l'heritage ne permet pas de faire
* une liste d'initialisation avec les attributs de la classe mere
*/

struct StatsBoss
{
    public:
        std::string name;
        int damage;
        int HP;
        int maxHP;
        int goldReward;
        RelicType relicReward;
};

#endif