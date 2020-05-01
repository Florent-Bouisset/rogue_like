#include "include/potion.h"

#include "include/champion.h"

using namespace std;

Potion::Potion(int p_healAmount){
    name = "Potion de vie";
    healAmount = p_healAmount;
}

void Potion::interact(Champion& champion){
    champion.changeHP(healAmount, ActionType::ADDITION);

}


shared_ptr<Potion> Potion::createPotion(){
    return make_shared<Potion>(25);
}