#include <string>
#include "include/fighter.h"
#include "include/enum.h"
#include <iostream>

using namespace std;

Fighter::Fighter(){
    this->name = "";
    this->HP = 0;
    this->MaxHP = 0;
    this->damage = 10;
}

Fighter::Fighter(string p_name, int p_HP, int p_MaxHP){
    this->name = p_name;
    this->MaxHP = 0;
    this->changeMaxHP(p_MaxHP, ActionType::ADDITION);
    this->HP = p_HP;
    this->damage = 15;
}

/**
 * Permet de faire gagner ou perdre des HP a l'fighter
 * entrer un entier positif pour en faire gagner et negatif pour faire perdre
 * HP ne peuvent pas depasser les HP max ni etre plus bas que 0
 */
void Fighter::changeHP(const int nbHP, const ActionType action){
    switch (action)
    {
    case SET:
        HP = nbHP;
        if(HP > MaxHP){
            HP = MaxHP;
        }
        break;

    case ADDITION:
        HP += nbHP;
        if(HP > MaxHP){
            HP = MaxHP;
        }
        break;

    case SOUSTRACT:
        HP -= nbHP;
        if(HP < 0){
            HP = 0;
        }
        break;

    default:
        break;
    }
}


/**
 * Permet de faire gagner ou perdre des HP Max au fighter
 * le parametre type Action decrit si on ajoute ou soustrait
 * HP Max ne peut pas etre plus bas que 1
 */
void Fighter::changeMaxHP(const int nbMaxHP, const ActionType action){
    switch (action)
    {

    case SET:
        MaxHP = nbMaxHP;
        break;

    case ADDITION:
        MaxHP += nbMaxHP;
        break;

    case SOUSTRACT:
        MaxHP -= nbMaxHP;
        if(MaxHP < 1){
            MaxHP = 1;
        }
        //Si HP actuel > Max HP alors diminue les HP actuels
        if(HP > MaxHP){
        HP = MaxHP;
        }

    default:
        break;
    }
}

/**
 * Permet de faire gagner ou perdre des damage a l'fighter
 * entrer un entier positif pour en faire gagner et negatif pour faire perdre
 * damage minimum = 1
 */
void Fighter::changeDamage(const int nbDamage, const ActionType action){
    switch (action)
    {

    case SET:
        damage = nbDamage;
        break;

    case ADDITION:
        damage += nbDamage;
        break;

    case SOUSTRACT:
        damage -= nbDamage;
        if (damage < 1){
            damage = 1;
        }
        break;

    default:
        break;
    }
}

bool Fighter::isAlive() const{
    return (HP > 0);
}

string Fighter::getName() const{
    return name;
}

int Fighter::getHP() const{
    return HP;
}

int Fighter::getMaxHP() const{
    return MaxHP;
}

int Fighter::getDamage() const{
    return damage;
}

void Fighter::attack(Fighter& target){
    target.changeHP(this->damage, ActionType::SOUSTRACT);
}

void Fighter::printHealth() const{
    cout << name << " " << HP << " HP " << MaxHP << " MaxHP" << endl;
}

void Fighter::setName(string p_name){
    this->name = p_name;
}