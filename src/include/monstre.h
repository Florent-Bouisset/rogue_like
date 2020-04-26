#ifndef MONSTRE
#define MONSTRE


#include "unite.h"

class Monstre : public Unite{
    public:
        Monstre();
        

    private:
        void donneNomAleatoire();
        int niveau;



};

#endif