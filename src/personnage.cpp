#include "include/personnage.h"
#include "include/unite.h"
#include <iostream>

using namespace std;

Personnage::Personnage(string nom) : Unite(nom, 100, 100){
    this->gold = 25;
}


void Personnage::afficheInfos(){
    cout << getNom() << " : PV = " << getPV() << " PV Max = " << getPVMax()
    << " Gold = " << gold << endl;
}

void Personnage::gagnerOr(int montantOr){
    gold = gold + montantOr;
}

/**
 * depenser l'or pour faire un achat
 * renvoie false si le joueur n a pas assez d'or
 * si le joueur na  pas assez d'or l'argent n'est pas depense 
 * 
 * */
bool Personnage::depenserOr(int montantOr){
    if(montantOr > gold){
        return false; // pas assez d'or pour achat
    }
    else {
        gold = gold - montantOr;
        return true;
    }
}

void Personnage::combattreMonstre(Monstre& cible){
    int cmptRound = 1;
    cout << "######### AVANT COMBAT ########" << endl;
    this->afficheVie();
    cible.afficheVie();
    while(this->estVivant() && cible.estVivant()){
        this->attaquer(cible);
        cible.attaquer(*this);

         cout << "#######   ROUND "<< cmptRound <<"  #########" << endl;
        this->afficheVie();
        cible.afficheVie();
        cmptRound += 1;
    }    
    this->afficheInfos();

}