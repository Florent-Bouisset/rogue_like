#include "include/relique.h"


using namespace std;

Relique::Relique(){

}

void Relique::modifierPV(Personnage& Cible, int quantite, typeAction action){
    Cible.modifierPV(quantite,action);

}

void Relique::modifierPVMax(Personnage& Cible, int quantite, typeAction action){
    Cible.modifierPVMax(quantite, action);
}

void Relique::modifierDegats(Personnage& Cible, int quantite, typeAction action){
    Cible.modifierDegats(quantite, action);
}


