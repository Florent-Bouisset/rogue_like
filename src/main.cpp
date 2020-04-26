#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/personnage.h"
#include "include/monstre.h"



using namespace std;

int main(){
    srand(time(NULL));


    //TEST



    Personnage guerrier = Personnage("Delmak");
    Monstre mob1 = Monstre();

    guerrier.combattreMonstre(mob1);



    //FIN TEST
    return 0;
}