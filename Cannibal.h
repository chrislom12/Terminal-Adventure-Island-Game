#ifndef CANNIBAL_H
#define CANNIBAL_H

#include "Enemy.h"


class Cannibal : public Enemy{
    public:
        Cannibal(std::string name, int hp, int dmg, std::string attack, std::string defense);
        ~Cannibal();
        bool hitSquadMember(SquadMember* z);//take instance of squad member (SquadMember* z)
        void celebrate();
        bool getHit(SquadMember* z);//take instance of squad member (SquadMember* z)
        void die();

};

#endif