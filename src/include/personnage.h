#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <vector>
#include <string>
#include "unite.h"
#include "monstre.h"
#include "relique.h"
#include "boss.h"

class Personnage : public Unite{
    public:
        Personnage(std::string nom);
        void afficheInfos();
        void modifierOr(int montantOr, typeAction action);
        void combattreMonstre(Monstre& cible);
        void combattreBoss(Boss& cible);
        void prendreRecompense(Monstre& cible);
        void prendreRecompense(Boss& cible);


    private:
        
        int gold;
        //std::vector<Relique> reliques;

};

#endif