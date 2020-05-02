#ifndef FIGHTER_H
#define FIGHTER_H

#include "enum.h"
#include <string>

class Fighter
{
public:
    Fighter();
    Fighter(std::string, int, int);
    void changeHP(const int nbHP, const ActionType);
    void changeMaxHP(const int nbMaxHP, const ActionType);
    void changeDamage(const int nbDamage, const ActionType);
    void attack(Fighter &target);
    bool isAlive() const;
    void printHealth() const;

    //getter
    int getMaxHP() const;
    int getHP() const;
    int getDamage() const;
    std::string getName() const;
    std::string getIllustrationPath() const;

    //setter
    void setName(std::string);

protected:
    std::string name;
    std::string illustrationPath;
    int MaxHP;
    int HP;
    int damage;
};

#endif