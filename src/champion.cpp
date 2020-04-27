#include "include/champion.h"
#include "include/unite.h"
#include "include/boss.h"
#include "include/relic.h"
#include <iostream>

using namespace std;

Champion::Champion(string nom) : Unite(nom, 100, 100){
    this->gold = 25;
}


void Champion::afficheInfos(){
    cout << getNom() << " : " << getHP() << " HP "  << getHPMax() << " HP Max " <<
    getDegats() << " Degats " << gold << " Gold "  << endl;
}

/**
 * change l'or du champion 
 * il n'y a pas de limite d'or 
 * et il ne peut pas avoir moins de 0 Or
 *  */

void Champion::changeOr(int montantOr, typeAction action){
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
 * permet au champion de combattre un monstre
 * le combat se fait en plusieurs round et s'arrete quand un des 
 * deux combattant est mort
 * 
 */

void Champion::fightAMonster(Monster& cible){
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


void Champion::fightABoss(Boss& cible){
    fightAMonster(cible);
    if(!cible.estVivant()){
 
    }
}
/**
 * Prend les recompenses d'un monstre 
 * donc augmente l'or du champion
 * 
 * */

void Champion::prendreRecompense(Monster& cible){
    this->changeOr(cible.getGainOr(),AJOUTER);
    cout << "recompense prise sur monster" << endl;
}

/**
 * Prends les recompenses d'un boss
 * cad les recompenses classique d'un combat normal
 * + une relic special
 * */

void Champion::prendreRecompense(Boss& cible){
    prendreRecompense((Monster&)cible);
    cible.getDrop().donnerBoost(*this);
    cout << "recompense prise sur boss" << endl;
}