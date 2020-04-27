#ifndef MONSTRE_H
#define MONSTRE_H


#include "unite.h"

class Monster : public Unite{
    public:
        Monster();
        int getGainOr();
        
    private:
        void attributTypeAleatoire();
        void attributUnNom();
        int level;
        int gainOr;
        TypeMonster typeMonster;



};

#endif