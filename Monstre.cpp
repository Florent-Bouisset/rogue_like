#include "Monstre.h"
#include "Unite.h"
#include <stdlib.h>                     //rand()
#include <vector>


using namespace std;

Monstre::Monstre(){    
    this->gagnerPVMax(50);
    this->gagnerPV(50);
    donneNomAleatoire();
}

void Monstre::donneNomAleatoire(){
    vector<string> noms = { "Troll", "Nekker", "Dragon", "Foenard", "Arakas",
     "Loup", "chien", "Noyeur", "Harpie"};
    int a = rand()%noms.size();
    this->setNom(noms[a]);
}