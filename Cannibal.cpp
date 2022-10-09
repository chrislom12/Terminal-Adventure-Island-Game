#include "Cannibal.h"


Cannibal::Cannibal(std::string name, int hp, int dmg, std::string attack, std::string defense)
{
    this->defenseMove = defense;
    this->attackMove = attack;
    this->name = name;
    this->hp = hp;
    this->dmg = dmg;
}

Cannibal::~Cannibal()
{
}




bool Cannibal::hitSquadMember(SquadMember* z)
{
    std::cout<<"Cannibal rushes towards " << z->getName() << " with a " << attackMove << "."<<std::endl;

   
    if(z->takeDamage(this->dmg) >0){
        return false;
    }
    else{
        if (z->getHP() < 0)
        {
            z->setHP(0);
        }
        return true;
    }
        
    

}

void Cannibal::celebrate()
{
    std::cout<<"Screams with his last breath, \"I am your father\"."<<std::endl;
}

bool Cannibal::getHit(SquadMember* z)
{
    std::cout<<"The other villagers come running deploying "<< defenseMove <<"."<<std::endl;

    this->hp -= z->getDmg();

    if(this->hp > 0){
        return false;
    }
    else{

        return true;
    }

}

void Cannibal::die()
{
    std::cout<<"Shakes his "<< attackMove << " at the player's remains." <<std::endl;
}