#include "include/boss.h"
#include "include/relic.h"
#include <vector>
#include <string>

using namespace std;

Boss::Boss(){    
    this->changeHPMax(50, typeAction::AJOUTER);
    this->changeHP(50, typeAction::AJOUTER);
    attributTypeAleatoire();
    attributRelic();
    attributUnNom();
}


void Boss::attributTypeAleatoire(){
    typeBoss = TypeBoss(rand() % COMPTEUR_BOSS);
}



void Boss::attributUnNom(){
    switch (typeBoss)
    {
    case COCATRIX:
        setNom("Cocatrix");
        break;

    case DAME_BLANCHE:
        setNom("Dame Blanche");
        break;

    case GRIFFON_ROYAL:
        setNom("Griffon Royal");
        break;
    
    case KATAKAN:
        setNom("Katakan");
        break;

    case WYVERN_ROYAL:
        setNom("Wyvern Royal");
        break;

    case FOENARD:
        setNom("Foenard");
        break;

    case LOUP_GAROU:
        setNom("Loup-Garou");
        break;

    default:
        break;
    }
}

void Boss::attributRelic(){
    switch (typeBoss)
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
