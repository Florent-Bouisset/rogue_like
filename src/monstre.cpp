#include "include/monstre.h"
#include "include/unite.h"
#include <stdlib.h>                     //rand()
#include <vector>


using namespace std;

Monstre::Monstre(){    
    this->modifierPVMax(50, typeAction::AJOUTER);
    this->modifierPV(50, typeAction::AJOUTER);
    this->gainOr = 12;
    attributTypeAleatoire();
    attributUnNom();
}


void Monstre::attributTypeAleatoire(){
    typeMonstre = TypeMonstre(rand() % COMPTEUR_MONSTRE);
}

void Monstre::attributUnNom(){
    switch (typeMonstre)
    {
    case NEKKER:
        setNom("Nekker");
        break;

    case ARAKAS:
        setNom("Arakas");
        break;

    case LOUP:
        setNom("Loup");
        break;
    
    case CHIEN:
        setNom("Chien");
        break;

    case NOYEUR:
        setNom("Noyeur");
        break;

    case HARPIE:
        setNom("Harpie");
        break;

    case OURS:
        setNom("Ours");
        break;

    case SIRENE:
        setNom("Sirene");

    default:
        setNom("Loup bugge");
        break;
    }
}

int Monstre::getGainOr(){
    return gainOr; 
}