#include "include/relique.h"
#include "include/enum.h"


using namespace std;

Relique::Relique(){
}

Relique::Relique(TypeRelique typeRelique){
    this->typeRelique = typeRelique; 
}

void Relique::modifierPV(Personnage& cible, int quantite, typeAction action){
    cible.modifierPV(quantite,action);

}

void Relique::modifierPVMax(Personnage& cible, int quantite, typeAction action){
    cible.modifierPVMax(quantite, action);
}

void Relique::modifierDegats(Personnage& cible, int quantite, typeAction action){
    cible.modifierDegats(quantite, action);
}

void Relique::donnerBoost(Personnage& cible){
    switch (typeRelique)
    {
    case ALTERE:
        modifierDegats(cible, 3 , AJOUTER);
        break;

    case ANANAS:
        modifierPVMax(cible, 6, AJOUTER);
        break;
    
    case JUS_CITRON:
        modifierPV(cible, 15, AJOUTER);
        break;

    case VIN_ROUGE:
        modifierPVMax(cible, 5, SOUSTRAIRE);
        modifierPV(cible,25, AJOUTER);
        break;

    case ARME_EMPOISONNEE:
        modifierPV(cible, 10, SOUSTRAIRE);
        modifierDegats(cible, 5, AJOUTER);
        break;

    default:
        break;
    }
}

