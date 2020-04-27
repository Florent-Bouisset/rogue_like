#include <string>
#include "include/unite.h"
#include "include/enum.h"
#include <iostream>

using namespace std;

Unite::Unite(){
    this->nom = "";
    this->HP = 0;
    this->HPMax = 0;
    this->degats = 10;
}

Unite::Unite(string nom, int HP, int HPMax){
    this->nom = nom;
    this->HPMax = 0;
    this->changeHPMax(HPMax, typeAction::AJOUTER);
    this->HP = HP;
    this->degats = 15;
}

/**
 * Permet de faire gagner ou perdre des HP a l'unite
 * entrer un entier positif pour en faire gagner et negatif pour faire perdre
 * HP ne peuvent pas depasser les HP max ni etre plus bas que 0
 */
void Unite::changeHP(int nbHP, typeAction action){
    switch (action)
    {
    case AJOUTER:
        HP += nbHP;
        if(HP > HPMax){
            HP = HPMax;
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
 * Permet de faire gagner ou perdre des HP Max a l'unite
 * le parametre type Action decrit si on ajoute ou soustrait
 * HP Max ne peut pas etre plus bas que 1
 */
void Unite::changeHPMax(int nbHPMax, typeAction action){
    switch (action)
    {
    case AJOUTER:
        HPMax += nbHPMax;
        break;
    
    case SOUSTRAIRE:
        HPMax -= nbHPMax;
        if(HPMax < 1){
            HPMax = 1;
        }
        //Si HP actuelle > Pv Max alors diminue les HP actuels
        if(HP > HPMax){
        HP = HPMax; 
        }

    default:
        break;
    }
} 

/**
 * Permet de faire gagner ou perdre des degats a l'unite
 * entrer un entier positif pour en faire gagner et negatif pour faire perdre
 * degats minimum = 1
 */
void Unite::changeDegats(int nbDegats, typeAction action){
    switch (action)
    {
    case AJOUTER:
        degats += nbDegats;
        break;
    
    case SOUSTRAIRE:
        degats -= nbDegats;
        if (degats < 1){
            degats = 1;
        }
        break;

    default:
        break;
    }
}

bool Unite::estVivant(){
    if(HP > 0){
        return true;
    }
    else {
        return false;
    }
}

string Unite::getNom(){
    return nom;
}

int Unite::getHP(){
    return HP;
}

int Unite::getHPMax(){
    return HPMax;
}

int Unite::getDegats(){
    return degats;
}

void Unite::attaquer(Unite& cible){
    cible.changeHP(this->degats, typeAction::SOUSTRAIRE);
}

void Unite::afficheVie(){
    cout << nom << " " << HP << " HP " << HPMax << " HPMax" << endl;
}

void Unite::setNom(string nom){
    this->nom = nom;
}