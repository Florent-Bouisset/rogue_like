#ifndef BOSS_H
#define BOSS_H

#include "monstre.h"
#include "enum.h"
#include "relique.h"

class Boss : public Monstre{
    public:
        Boss();
        Relique getDrop();

    private:
        void attributTypeAleatoire();
        void attributUnNom();
        void attributRelique();
        TypeBoss typeBoss;
        Relique drop;

};

#endif