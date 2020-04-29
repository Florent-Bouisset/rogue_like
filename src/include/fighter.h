#ifndef FIGHTER_H
#define FIGHTER_H

#include "enum.h"
#include <string>

class Fighter{
    public:
        Fighter();
        Fighter(std::string, int, int);
        void changeHP(int nbHP, ActionType);
        void changeMaxHP(int nbMaxHP, ActionType);
        void changeDamage(int nbDamage, ActionType);
        void attack(Fighter& target);
        bool isAlive();
        void printHealth();

        //getter
        int getMaxHP();
        int getHP();
        int getDamage();
        std::string getName();

        //setter
        void setName(std::string);

    protected:
        std::string name;
        int MaxHP;
        int HP;
        int damage;
};

#endif