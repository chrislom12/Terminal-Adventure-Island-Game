#ifndef ENEMY_H
#define ENEMY_H
#include "SquadMember.h"
#include <iostream>
#include <string>

class Enemy{
    protected:
        int hp;
        int dmg;
        std::string name, attackMove, defenseMove;

    public:
       
        Enemy();
        ~Enemy();
        void attack(SquadMember* z);//take instance of squad member (SquadMember* z)hit        virtual bool hitSquadMember(SquadMember* z) = 0;//take instance of squad member (SquadMember* z)
        virtual bool hitSquadMember(SquadMember* z) = 0;
        virtual void celebrate() = 0;
        virtual bool getHit(SquadMember* z) = 0;//take instance of squad member (SquadMember* z)
        virtual void die() = 0;
        std::string getName(){return name;}
        int getHp(){return hp;}


};

#endif