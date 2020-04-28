#include "include/relic.h"
#include "include/champion.h"
#include <string>


using namespace std;

Relic::Relic(){
}

Relic::Relic(RelicType relicType){
    this->relicType = relicType;
    this->giveAName();
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
    switch (relicType)
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

void Relic::giveARandomType(){
    relicType = RelicType(rand() % COMPTEUR_RELIQUE);
}

void Relic::giveAName(){
    switch (relicType)
    {
    case ALTERE:
        name = "Altere";
        break;

    case ANANAS:
        name = "Ananas";
        break;

    case JUS_CITRON:
        name = "Jus de citron";
        break;

    case VIN_ROUGE:
        name = "Vin rouge";
        break;

    case ARME_EMPOISONNEE:
        name = "Arme empoisonnee";
        break;

    default:
        break;
    }
}

string Relic::getName(){
    return name;
}