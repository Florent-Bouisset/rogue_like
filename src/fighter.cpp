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

Fighter::Fighter(string name, int HP, int MaxHP){
    this->name = name;
    this->MaxHP = 0;
    this->changeMaxHP(MaxHP, ActionType::ADDITION);
    this->HP = HP;
    this->damage = 15;
}

/**
 * Permet de faire gagner ou perdre des HP a l'fighter
 * entrer un entier positif pour en faire gagner et negatif pour faire perdre
 * HP ne peuvent pas depasser les HP max ni etre plus bas que 0
 */
void Fighter::changeHP(int nbHP, ActionType action){
    switch (action)
    {
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
void Fighter::changeMaxHP(int nbMaxHP, ActionType action){
    switch (action)
    {
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
void Fighter::changeDamage(int nbDamage, ActionType action){
    switch (action)
    {
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

bool Fighter::isAlive(){
    if(HP > 0){
        return true;
    }
    else {
        return false;
    }
}

string Fighter::getName(){
    return name;
}

int Fighter::getHP(){
    return HP;
}

int Fighter::getMaxHP(){
    return MaxHP;
}

int Fighter::getDamage(){
    return damage;
}

void Fighter::attack(Fighter& target){
    target.changeHP(this->damage, ActionType::SOUSTRACT);
}

void Fighter::printHealth(){
    cout << name << " " << HP << " HP " << MaxHP << " MaxHP" << endl;
}

void Fighter::setName(string name){
    this->name = name;
}