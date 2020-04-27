#include "include/boss.h"
#include "include/relic.h"
#include <vector>
#include <string>

using namespace std;

Boss::Boss(){    
    this->changeMaxHP(50, ActionType::ADDITION);
    this->changeHP(50, ActionType::ADDITION);
    GiveARandomType();
    GiveARelic();
    GiveAName();
}


void Boss::GiveARandomType(){
    bossType = BossType(rand() % COMPTEUR_BOSS);
}



void Boss::GiveAName(){
    switch (bossType)
    {
    case COCATRIX:
        setName("Cocatrix");
        break;

    case DAME_BLANCHE:
        setName("Dame Blanche");
        break;

    case GRIFFON_ROYAL:
        setName("Griffon Royal");
        break;
    
    case KATAKAN:
        setName("Katakan");
        break;

    case WYVERN_ROYAL:
        setName("Wyvern Royal");
        break;

    case FOENARD:
        setName("Foenard");
        break;

    case LOUP_GAROU:
        setName("Loup-Garou");
        break;

    default:
        break;
    }
}

void Boss::GiveARelic(){
    switch (bossType)
    {
    case COCATRIX:
        drop = Relic(ALTERE);
        break;

    case DAME_BLANCHE:
        drop = Relic(ARME_EMPOISONNEE);
        break;

    case GRIFFON_ROYAL:
        drop = Relic(ANANAS);
        break;
    
    case KATAKAN:
        drop = Relic(VIN_ROUGE);
        break;

    case WYVERN_ROYAL:
        drop = Relic(ARME_EMPOISONNEE);
        break;

    case FOENARD:
        drop = Relic(JUS_CITRON);
        break;

    case LOUP_GAROU:
        drop = Relic(ANANAS);
        break;

    default:
        drop = Relic(ALTERE);
        break;
    }
}

Relic Boss::getDrop(){
    return drop;
}
