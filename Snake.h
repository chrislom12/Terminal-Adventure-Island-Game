#ifndef SNAKE_H
#define SNAKE_H

#include "Enemy.h"


class Snake : public Enemy{
    public:
        Snake(std::string name, int hp, int dmg, std::string attack, std::string defense);
        ~Snake();
        bool hitSquadMember(SquadMember* z);//take instance of squad member (SquadMember* z)
        void celebrate();
        bool getHit(SquadMember* z);//take instance of squad member (SquadMember* z)
        void die();

};

#endif