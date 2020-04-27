#include <string>
#include "include/unite.h"
#include "include/enum.h"
#include <iostream>

using namespace std;

Unite::Unite(){
    this->nom = "";
    this->PV = 0;
    this->PVMax = 0;
    this->degats = 10;
}

Unite::Unite(string nom, int PV, int PVMax){
    this->nom = nom;
    this->PVMax = 0;
    this->modifierPVMax(PVMax, typeAction::AJOUTER);
    this->PV = PV;
    this->degats = 15;
}

/**
 * Permet de faire gagner ou perdre des PV a l'unite
 * entrer un entier positif pour en faire gagner et negatif pour faire perdre
 * PV ne peuvent pas depasser les PV max ni etre plus bas que 0
 */
void Unite::modifierPV(int nbPV, typeAction action){
    switch (action)
    {
    case AJOUTER:
        PV += nbPV;
        if(PV > PVMax){
            PV = PVMax;
        }
        break;
    
    case SOUSTRAIRE:
        PV -= nbPV;
        if(PV < 0){
            PV = 0;
        }
        break;
    
    default:
        break;
    }    
} 


/**
 * Permet de faire gagner ou perdre des PV Max a l'unite
 * le parametre type Action decrit si on ajoute ou soustrait
 * PV Max ne peut pas etre plus bas que 1
 */
void Unite::modifierPVMax(int nbPVMax, typeAction action){
    switch (action)
    {
    case AJOUTER:
        PVMax += nbPVMax;
        break;
    
    case SOUSTRAIRE:
        PVMax -= nbPVMax;
        if(PVMax < 1){
            PVMax = 1;
        }
        //Si PV actuelle > Pv Max alors diminue les PV actuels
        if(PV > PVMax){
        PV = PVMax; 
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
void Unite::modifierDegats(int nbDegats, typeAction action){
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
    if(PV > 0){
        return true;
    }
    else {
        return false;
    }
}

string Unite::getNom(){
    return nom;
}

int Unite::getPV(){
    return PV;
}

int Unite::getPVMax(){
    return PVMax;
}

int Unite::getDegats(){
    return degats;
}

void Unite::attaquer(Unite& cible){
    cible.modifierPV(this->degats, typeAction::SOUSTRAIRE);
}

void Unite::afficheVie(){
    cout << nom << " " << PV << " PV " << PVMax << " PVMax" << endl;
}

void Unite::setNom(string nom){
    this->nom = nom;
}