#ifndef POTION_H
#define POTION_H

#include "item.h"
#include <memory>

class Potion : public Item{

    public:
        Potion(int amount);
        void interact(Champion& champion);
        static std::shared_ptr<Potion> createPotion();
    protected:
        int healAmount;

};




#endif