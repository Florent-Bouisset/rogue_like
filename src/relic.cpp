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
        changeDamage(target, 3, ADDITION);
        break;

    case ANANAS:
        changeMaxHP(target, 6, ADDITION);
        break;
    
    case JUS_CITRON:
        changeHP(target, 15, ADDITION);
        break;

    case VIN_ROUGE:
        changeMaxHP(target, 5, SOUSTRACT);
        changeHP(target, 25, ADDITION);
        break;

    case ARME_EMPOISONNEE:
        changeHP(target, 10, SOUSTRACT);
        changeDamage(target, 5, ADDITION);
        break;

    default:
        break;
    }
}

