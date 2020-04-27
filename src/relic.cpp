#include "include/relic.h"
#include "include/enum.h"
#include "include/champion.h"


using namespace std;

Relic::Relic(){
}

Relic::Relic(RelicType typeRelic){
    this->typeRelic = typeRelic; 
}

void Relic::changeHP(Champion& target, int amount, ActionType action){
    target.changeHP(amount,action);

}

void Relic::changeMaxHP(Champion& target, int amount, ActionType action){
    target.changeMaxHP(amount, action);
}

void Relic::changeDamage(Champion& target, int amount, ActionType action){
    target.changeDamage(amount, action);
}

void Relic::giveABoost(Champion& target){
    switch (typeRelic)
    {
    case ALTERE:
        changeDamage(target, 3 , AJOUTER);
        break;

    case ANANAS:
        changeMaxHP(target, 6, AJOUTER);
        break;
    
    case JUS_CITRON:
        changeHP(target, 15, AJOUTER);
        break;

    case VIN_ROUGE:
        changeMaxHP(target, 5, SOUSTRAIRE);
        changeHP(target,25, AJOUTER);
        break;

    case ARME_EMPOISONNEE:
        changeHP(target, 10, SOUSTRAIRE);
        changeDamage(target, 5, AJOUTER);
        break;

    default:
        break;
    }
}

