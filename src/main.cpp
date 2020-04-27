#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "include/personnage.h"
#include "include/monstre.h"
#include "include/boss.h"



using namespace std;

int main(){
    srand(time(NULL));


    //TEST



    Personnage guerrier = Personnage("Delmak");
    Monstre mob1 = Monstre();
    Boss boss1 = Boss();

    cout << mob1.getNom() <<endl;
    cout << boss1.getNom() <<endl;
    //guerrier.combattreMonstre(mob1);
    guerrier.combattreMonstre(boss1);
    boss1.getDrop().donnerBoost(guerrier);
    guerrier.afficheInfos();


    //FIN TEST
    return 0;
}