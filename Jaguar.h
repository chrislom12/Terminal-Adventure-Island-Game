#ifndef JAGUAR_H
#define JAGUAR_H

#include "Enemy.h"


class Jaguar : public Enemy{
    public:
        Jaguar(std::string name, int hp, int dmg, std::string attack, std::string defense);
        ~Jaguar();
        bool hitSquadMember(SquadMember* z);//take instance of squad member (SquadMember* z)
        void celebrate();
        bool getHit(SquadMember* z);//take instance of squad member (SquadMember* z)
        void die();

};

#endif