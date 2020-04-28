#include "include/champion.h"
#include "include/boss.h"
#include "include/relic.h"
#include <iostream>

using namespace std;

Champion::Champion(string name) : Fighter(name, 100, 100){
    this->gold = 25;
}


void Champion::printInfos(){
    cout << getName() << " : " << getHP() << " HP "  << getMaxHP() << " HP Max " <<
    getDamage() << " Damage " << gold << " Gold "  << endl;
}

/**
 * change l'or du champion 
 * il n'y a pas de limite d'or 
 * et il ne peut pas avoir moins de 0 Or
 *  */

void Champion::changeGold(int goldAmount, ActionType action){
    switch (action)
    {
    case ADDITION:
        gold += goldAmount;
        break;

    case SOUSTRACT:
        if(goldAmount > gold){
            gold = 0;
            break;
        }
        else {
            gold = gold - goldAmount;
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

void Champion::fightAMonster(Monster& target){
    int roundCount = 1;
    cout << "######### AVANT COMBAT ########" << endl;
    this->printHealth();
    target.printHealth();
    while(this->isAlive() && target.isAlive()){
        this->attack(target);
        target.attack(*this);

         cout << "#######   ROUND "<< roundCount <<"  #########" << endl;
        this->printHealth();
        target.printHealth();
        roundCount += 1;
    }

    cout << "######## FIN DU COMBAT ######### \n";
    this->printInfos();
}


void Champion::fightABoss(Boss& target){
    fightAMonster(target);
    if(!target.isAlive()){
 
    }
}
/**
 * Prend les recompenses d'un monstre 
 * donc augmente l'or du champion
 * 
 * */

void Champion::takeRewards(Monster& target){
    this->changeGold(target.getGoldReward(), ADDITION);
    cout << "Ce combat vous donne " << target.getGoldReward() 
        << " pieces d'or ! " << endl; 
}

/**
 * Prends les recompenses d'un boss
 * cad les recompenses classique d'un combat normal
 * + une relic special
 * */

void Champion::takeRewards(Boss& target){
    takeRewards((Monster&)target);
    target.getDrop().giveABoost(*this);
    cout << "Ce combat vous donne la relique " << 
    target.getDrop().getName() << " ! " << endl;
}