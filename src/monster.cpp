#include "include/monster.h"
#include "include/unite.h"
#include <stdlib.h>                     //rand()
#include <vector>


using namespace std;

Monster::Monster(){    
    this->changeHPMax(50, typeAction::AJOUTER);
    this->changeHP(50, typeAction::AJOUTER);
    this->gainOr = 12;
    attributTypeAleatoire();
    attributUnNom();
}


void Monster::attributTypeAleatoire(){
    typeMonster = TypeMonster(rand() % COMPTEUR_MONSTRE);
}

void Monster::attributUnNom(){
    switch (typeMonster)
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

int Monster::getGainOr(){
    return gainOr; 
}