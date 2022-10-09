#include "Jaguar.h"

Jaguar::Jaguar(std::string name, int hp, int dmg, std::string attack, std::string defense)
{
    this->defenseMove = defense;
    this->attackMove = attack;
    this->name = name;
    this->hp = hp;
    this->dmg = dmg;
}

Jaguar::~Jaguar()
{
}

bool Jaguar::hitSquadMember(SquadMember *z)
{
    std::cout << "Jaguar leaps toward the " << z->getName() << " and deliver's a forceful " << attackMove << "." << std::endl;

    if (z->takeDamage(this->dmg) > 0)
    {
        return false;
    }
    else
    {
        if (z->getHP() < 0)
        {
            z->setHP(0);
        }
        return true;
    }
}

void Jaguar::celebrate()
{
    std::cout << "Should have fought harder soldier." << std::endl;
}

bool Jaguar::getHit(SquadMember *z)
{
    std::cout << "Growls in pain as he is maimed. Jaguar turns around and delivers " << defenseMove << " against " << z->getName() << "." << std::endl;
    this->hp -= z->getDmg();
    if (this->hp < 0)
    {
        this->hp = 0;
    }

    if (this->hp > 0)
    {
        return false;
    }
    else
    {

        return true;
    }
}

void Jaguar::die()
{
    std::cout << "Gives one last growl before falling over." << std::endl;
}