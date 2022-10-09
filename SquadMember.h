#ifndef SQUADMEMBER_H
#define SQUADMEMBER_H

#include <string>

class SquadMember{
    public:
        SquadMember(int hp, int dmg, std::string name);
        ~SquadMember();

        int getHP();
        int getDmg();
        std::string getName();
        bool getAlive();
        

        void setHP(int newHP);
        void setDmg(int newHP);
        void dies();
        void setAlive(bool val);
        int takeDamage(int dmg);
        SquadMember* clone();



    private:
        unsigned int hp;
        int dmg;
        std::string name;
        bool isAlive;
        
        

};

#endif