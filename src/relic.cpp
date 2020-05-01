#include "include/relic.h"

#include "include/champion.h"
#include <string>
#include <memory>

using namespace std;

Relic::Relic(){
}

Relic::Relic(RelicType p_relicType){
    this->relicType = p_relicType;
    this->giveNameFromMap();
}

map<RelicType, string> Relic::namesMap = {
    {ALTERE, "Altere"},
    {ANANAS, "Ananas"},
    {JUS_CITRON, "Jus de citron"},
    {VIN_ROUGE, "Vin rouge"},
    {ARME_EMPOISONNEE, "Arme empoisonnee"}
};

void Relic::giveNameFromMap(){
    if(namesMap.find(relicType) != namesMap.end()){
        name = namesMap.find(relicType)->second;
    }
    else{
        name = "Relique inconnue";
    }
}

void Relic::changeHP(Champion& target, const int amount, const ActionType action){
    target.changeHP(amount,action);
}

void Relic::changeMaxHP(Champion& target, const int amount, const ActionType action){
    target.changeMaxHP(amount, action);
}

void Relic::changeDamage(Champion& target, const int amount, const ActionType action){
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
    relicType = RelicType(rand() % namesMap.size());
}


string Relic::getName() const{
    return name;
}

void Relic::interact(Champion& champion){
    giveABoost(champion);
}

shared_ptr<Relic> Relic::createRelic(){
    RelicType type = RelicType(rand() % namesMap.size());
    return make_shared<Relic>(type);
}