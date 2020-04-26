#ifndef BOSS
#define BOSS
#include "monstre.h"
#include "relique.h"


class Boss : Monstre{
    public:
        Boss();

    private:
        Relique drop;

};

#endif