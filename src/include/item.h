#ifndef ITEM_H
#define ITEM_H

class Champion;

#include <string>

class Item{
    public:
        std::string getName();
        virtual void interact(Champion& champion) = 0;

    protected:
        std::string name;
};




#endif