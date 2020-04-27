#include "include/relic.h"
#include "include/enum.h"
#include "include/champion.h"


using namespace std;

Relic::Relic(){
}

Relic::Relic(TypeRelic typeRelic){
    this->typeRelic = typeRelic; 
}

void Relic::changeHP(Champion& cible, int quantite, typeAction action){
    cible.changeHP(quantite,action);

}

void Relic::changeHPMax(Champion& cible, int quantite, typeAction action){
    cible.changeHPMax(quantite, action);
}

void Relic::changeDegats(Champion& cible, int quantite, typeAction action){
    cible.changeDegats(quantite, action);
}

void Relic::donnerBoost(Champion& cible){
    switch (typeRelic)
    {
    case ALTERE:
        changeDegats(cible, 3 , AJOUTER);
        break;

    case ANANAS:
        changeHPMax(cible, 6, AJOUTER);
        break;
    
    case JUS_CITRON:
        changeHP(cible, 15, AJOUTER);
        break;

    case VIN_ROUGE:
        changeHPMax(cible, 5, SOUSTRAIRE);
        changeHP(cible,25, AJOUTER);
        break;

    case ARME_EMPOISONNEE:
        changeHP(cible, 10, SOUSTRAIRE);
        changeDegats(cible, 5, AJOUTER);
        break;

    default:
        break;
    }
}

