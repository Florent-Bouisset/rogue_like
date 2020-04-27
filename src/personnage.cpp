#include "include/personnage.h"
#include "include/unite.h"
#include "include/boss.h"
#include "include/relique.h"
#include <iostream>

using namespace std;

Personnage::Personnage(string nom) : Unite(nom, 100, 100){
    this->gold = 25;
}


void Personnage::afficheInfos(){
    cout << getNom() << " : " << getPV() << " PV "  << getPVMax() << " PV Max " <<
    getDegats() << " Degats " << gold << " Gold "  << endl;
}

/**
 * modifier l'or du personnage 
 * il n'y a pas de limite d'or 
 * et il ne peut pas avoir moins de 0 Or
 *  */

void Personnage::modifierOr(int montantOr, typeAction action){
    switch (action)
    {
    case AJOUTER:
        gold += montantOr;
        break;

    case SOUSTRAIRE:
        if(montantOr > gold){
            gold = 0;
            break;
        }
        else {
            gold = gold - montantOr;
            break;
        }
        
    default:
        break;
    }
}


/**
 * permet au personnage de combattre un monstre
 * le combat se fait en plusieurs round et s'arrete quand un des 
 * deux combattant est mort
 * 
 */

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

    cout << "######## FIN DU COMBAT ######### \n";
    this->afficheInfos();
}


void Personnage::combattreBoss(Boss& cible){
    combattreMonstre(cible);
    if(!cible.estVivant()){

    }
}

void Personnage::prendreRecommpense(Monstre& cible){
    this->modifierOr(10,AJOUTER);
}