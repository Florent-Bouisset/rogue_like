#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "include/champion.h"
#include "include/monster.h"
#include "include/boss.h"



using namespace std;

int main(){
    srand(time(NULL));


    //TEST



    Champion guerrier = Champion("Delmak");
    Monster mob1 = Monster();
    Boss boss1 = Boss();

    cout << mob1.getNom() <<endl;
    cout << boss1.getNom() <<endl;
    //guerrier.fightAMonster(mob1);
    guerrier.fightAMonster(boss1);
    guerrier.prendreRecompense(boss1);
    //boss1.getDrop().donnerBoost(guerrier);
    guerrier.afficheInfos();


    //FIN TEST
    return 0;
}