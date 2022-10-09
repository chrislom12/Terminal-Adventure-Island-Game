#include "Gorilla.h"


Gorilla::Gorilla(std::string name, int hp, int dmg, std::string attack, std::string defense)
{
    this->defenseMove = defense;
    this->attackMove = attack;
    this->name = name;
    this->hp = hp;
    this->dmg = dmg;
}

Gorilla::~Gorilla()
{
}





bool Gorilla::hitSquadMember(SquadMember* z)
{
    std::cout<<"Gorilla slams his fists on the ground, growls and hits " << z->getName() << " with " << attackMove << "."<<std::endl;
    
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

void Gorilla::celebrate()
{
    std::cout<<"Player tried in vain trying to save himself."<<std::endl;
}

bool Gorilla::getHit(SquadMember* z)
{
        std::cout<<"Roars and hits his chest in anger."<<std::endl;
        this->hp -= z->getDmg();
        if(this->hp<0){
            this->hp=0;
        }

        if(this->hp > 0){
            return false;
        }
        else{

            return true;
        }
}

void Gorilla::die()
{
    std::cout<<"The earth shakes as the gorilla falls to the ground."<<std::endl;
}