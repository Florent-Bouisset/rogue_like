#ifndef PERSONNAGE
#define PERSONNAGE


#include <string>
#include "unite.h"
#include "Monstre.h"

class Personnage : public Unite{
    public:
        Personnage(std::string nom);
        void afficheInfos();
        void gagnerOr(int montantOr);
        bool depenserOr(int montantOr);
        void combattreMonstre(Monstre& cible);

    private:

        int gold;

};

#endif