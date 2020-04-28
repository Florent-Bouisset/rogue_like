#include "include/monster.h"
#include <stdlib.h>                     //rand()


using namespace std;

Monster::Monster(){
    this->changeMaxHP(50, ActionType::ADDITION);
    this->changeHP(50, ActionType::ADDITION);
    this->goldReward = 12;
    this->giveARandomType();
    this->giveAName();
}


void Monster::giveARandomType(){
    typeMonster = MonsterType(rand() % COMPTEUR_MONSTRE);
}

void Monster::giveAName(){
    switch (typeMonster)
    {
    case NEKKER:
        setName("Nekker");
        break;

    case ARAKAS:
        setName("Arakas");
        break;

    case LOUP:
        setName("Loup");
        break;

    case CHIEN:
        setName("Chien");
        break;

    case NOYEUR:
        setName("Noyeur");
        break;

    case HARPIE:
        setName("Harpie");
        break;

    case OURS:
        setName("Ours");
        break;

    case SIRENE:
        setName("Sirene");

    default:
        setName("Loup bugge");
        break;
    }
}

int Monster::getGoldReward(){
    return goldReward;
}