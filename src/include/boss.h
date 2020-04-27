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
        void attributTypeAleatoire();
        void attributUnNom();
        void attributRelic();
        TypeBoss typeBoss;
        Relic drop;

};

#endif