#ifndef BOSS_H
#define BOSS_H

#include "monstre.h"
#include "relique.h"


class Boss : Monstre{
    public:
        Boss();

    private:
        Relique drop;

};

#endif