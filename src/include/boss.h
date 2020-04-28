#ifndef BOSS_H
#define BOSS_H

#include "monster.h"
#include "enum.h"
#include "relic.h"

class Boss : public Monster{
    public:
        Boss();
        Relic getDrop();

    private:
        void giveARandomType();
        void giveAName();
        void giveARelic();
        BossType bossType;
        Relic drop;
};

#endif