#ifndef GORILLA_H
#define GORILLA_H

#include "Enemy.h"


class Gorilla : public Enemy{
    public:
        Gorilla(std::string name, int hp, int dmg, std::string attack, std::string defense);
        ~Gorilla();
        bool hitSquadMember(SquadMember* z);//take instance of squad member (SquadMember* z)
        void celebrate();
        bool getHit(SquadMember* z);//take instance of squad member (SquadMember* z)
        void die();

};

#endif