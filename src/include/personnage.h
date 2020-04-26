#ifndef PERSONNAGE
#define PERSONNAGE


#include <string>
#include "unite.h"
#include "monstre.h"
#include "relique.h"
#include <vector>

class Personnage : public Unite{
    public:
        Personnage(std::string nom);
        void afficheInfos();
        void gagnerOr(int montantOr);
        bool depenserOr(int montantOr);
        void combattreMonstre(Monstre& cible);

    private:

        int gold;
        
        std::vector<Relique> reliques;

};

#endif