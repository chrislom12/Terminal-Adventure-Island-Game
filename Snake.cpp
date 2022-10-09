#include "Snake.h"


Snake::Snake(std::string name, int hp, int dmg, std::string attack, std::string defense)
{
    this->defenseMove = defense;
    this->attackMove = attack;
    this->name = name;
    this->hp = hp;
    this->dmg = dmg;
}

Snake::~Snake()
{
}





bool Snake::hitSquadMember(SquadMember* z)
{
    std::cout<<"Snake wraps around " << z->getName() << " and uses " << attackMove << "."<<std::endl;
    
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

void Snake::celebrate()
{
    std::cout<<"Player tried strongly till the end."<<std::endl;
}

bool Snake::getHit(SquadMember* z)
{
    std::cout<<"Slithers rapidly searching for safety and employs "<< defenseMove << "."<<std::endl;
    this->hp -= z->getDmg();

    if(this->hp > 0){
        return false;
    }
    else{
        return true;
    }
}

void Snake::die()
{
    std::cout<<"Hisses and curls up as he is defeated."<<std::endl;
}