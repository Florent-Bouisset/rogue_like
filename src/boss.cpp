#include "include/boss.h"
#include <vector>
#include <string>

using namespace std;

Boss::Boss(){    
    this->modifierPVMax(50, typeAction::AJOUTER);
    this->modifierPV(50, typeAction::AJOUTER);
    donneTypeAleatoire();
    attributRelique();
    attributUnNom();
}


void Boss::donneTypeAleatoire(){
    typeBoss = TypeBoss(rand() % COMPTEUR_BOSS);
}

void Boss::donneNomAleatoire(){
    // pas sur que la methode suivante soit bonne
    vector<string> noms = { "Cocatrix", "Dame Blanche", "Griffon royal", "Katakan",
    "Moires", "Wyvern royal", "Foenard", "Loup Garou"};
    int a = rand()%noms.size();
    this->setNom(noms[a]);
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

void Boss::attributRelique(){
    switch (typeBoss)
    {
    case COCATRIX:
        drop = Relique(ALTERE);
        break;

    case DAME_BLANCHE:
        drop = Relique(ARME_EMPOISONNEE);
        break;

    case GRIFFON_ROYAL:
        drop = Relique(ANANAS);
        break;
    
    case KATAKAN:
        drop = Relique(VIN_ROUGE);
        break;

    case WYVERN_ROYAL:
        drop = Relique(ARME_EMPOISONNEE);
        break;

    case FOENARD:
        drop = Relique(JUS_CITRON);
        break;

    case LOUP_GAROU:
        drop = Relique(ANANAS);
        break;

    default:
        drop = Relique(ALTERE);
        break;
    }
}