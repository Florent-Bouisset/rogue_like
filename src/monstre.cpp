#include "include/monstre.h"
#include "include/unite.h"
#include <stdlib.h>                     //rand()
#include <vector>


using namespace std;

Monstre::Monstre(){    
    this->modifierPVMax(50, typeAction::AJOUTER);
    this->modifierPV(50, typeAction::AJOUTER);
    donneNomAleatoire();
}

void Monstre::donneNomAleatoire(){
    // pas sur que la methode suivante soit bonne
    vector<string> noms = { "Troll", "Nekker", "Arakas",
     "Loup", "chien", "Noyeur", "Harpie","Ours"};
    int a = rand()%noms.size();
    this->setNom(noms[a]);
}