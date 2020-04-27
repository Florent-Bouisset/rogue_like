#include <string>
#include "include/fighter.h"
#include "include/enum.h"
#include <iostream>

using namespace std;

Fighter::Fighter(){
    this->nom = "";
    this->HP = 0;
    this->MaxHP = 0;
    this->damage = 10;
}

Fighter::Fighter(string nom, int HP, int MaxHP){
    this->nom = nom;
    this->MaxHP = 0;
    this->changeMaxHP(MaxHP, ActionType::AJOUTER);
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
    case AJOUTER:
        HP += nbHP;
        if(HP > MaxHP){
            HP = MaxHP;
        }
        break;
    
    case SOUSTRAIRE:
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
 * Permet de faire gagner ou perdre des HP Max a l'fighter
 * le parametre type Action decrit si on ajoute ou soustrait
 * HP Max ne peut pas etre plus bas que 1
 */
void Fighter::changeMaxHP(int nbMaxHP, ActionType action){
    switch (action)
    {
    case AJOUTER:
        MaxHP += nbMaxHP;
        break;
    
    case SOUSTRAIRE:
        MaxHP -= nbMaxHP;
        if(MaxHP < 1){
            MaxHP = 1;
        }
        //Si HP actuelle > Pv Max alors diminue les HP actuels
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
    case AJOUTER:
        damage += nbDamage;
        break;
    
    case SOUSTRAIRE:
        damage -= nbDamage;
        if (damage < 1){
            damage = 1;
        }
        break;

    default:
        break;
    }
}

bool Fighter::estVivant(){
    if(HP > 0){
        return true;
    }
    else {
        return false;
    }
}

string Fighter::getName(){
    return nom;
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

void Fighter::attaquer(Fighter& target){
    target.changeHP(this->damage, ActionType::SOUSTRAIRE);
}

void Fighter::afficheVie(){
    cout << nom << " " << HP << " HP " << MaxHP << " MaxHP" << endl;
}

void Fighter::setName(string nom){
    this->nom = nom;
}