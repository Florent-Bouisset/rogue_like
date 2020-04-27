#ifndef BOSS_H
#define BOSS_H

#include "monstre.h"
#include "relique.h"
#include "enum.h"


class Boss : public Monstre{
    public:
        Boss();

    private:
        void donneTypeAleatoire();
        void attributUnNom();
        void donneNomAleatoire();
        void attributRelique();
        TypeBoss typeBoss;
        Relique drop;

};

#endif