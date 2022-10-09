#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "Enemy.h"
#include <string>

class EnemyFactory{

    public:
        EnemyFactory();
        virtual ~EnemyFactory(){}
        virtual Enemy* createEnemy(std::string attack, std::string defense) = 0;
    protected:
        std::string getName();

    private:
        std::string names[15] = {"Chris", "John", "Lila" , "Peter", "Iver", "Jack", "Nick", "Andrea", "Seri", "Lydia", "Amy", "Icker", "Bloo", "Zoop", "Blub"};
        std::string surnames[15] = {"Woods", "Aber", "Tiver" , "Bush", "Obama", "Lillipold", "Baker", "Makal", "Nim", "Skywalker", "Dabhaby", "lezgo", "Inker", "Plum", "Mustard"};

        
};

#endif