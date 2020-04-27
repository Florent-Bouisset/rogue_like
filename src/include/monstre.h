#ifndef MONSTRE_H
#define MONSTRE_H


#include "unite.h"

class Monstre : public Unite{
    public:
        Monstre();
        
    private:
        void attributTypeAleatoire();
        void attributUnNom();
        int niveau;
        int gainOr;
        TypeMonstre typeMonstre;



};

#endif