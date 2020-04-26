#include <string>
#include "unite.h"
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
    this->PV = PV;
    this->PVMax = 0;
    this->gagnerPVMax(PVMax);
    this->degats = 15;
}

void Unite::gagnerPV(int nbPV){
        
    if((nbPV + PV) > PVMax){
        PV = PVMax;
    }
    else {
        PV = PV + nbPV;
    }
} 

void Unite::perdrePV(int nbPV){
    if((PV - nbPV) < 0){
        PV = 0;
    }
    else {
        PV = PV - nbPV;
    }
}


void Unite::gagnerPVMax(int nbPVMax){
    PVMax += nbPVMax;
} 

void Unite::perdrePVMax(int nbPVMax){
    if(PVMax - nbPVMax < 1){
        PVMax = 1;
    }
    else
    {
        PVMax -= nbPVMax;
    }

    if(PV > PVMax){
        PV = PVMax; 
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

void Unite::attaquer(Unite& cible){
    cible.perdrePV(this->degats);
}

void Unite::afficheVie(){
    cout << nom << " : PV = " << PV << " : PV Max = " << PVMax << endl;
}

void Unite::setNom(string nom){
    this->nom = nom;
}