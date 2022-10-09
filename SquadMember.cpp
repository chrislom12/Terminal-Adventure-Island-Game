#include "SquadMember.h"

SquadMember::SquadMember(int hp, int dmg, std::string name){
    this->hp = hp;
    this->dmg = dmg;
    this->name = name;
    this->isAlive = true;
}

SquadMember::~SquadMember(){
    
}

int SquadMember::getHP(){
    return this->hp;
}

int SquadMember::getDmg(){
    return this->dmg;
}

std::string SquadMember::getName(){
    return this->name;
}

bool SquadMember::getAlive(){
    return this->isAlive;
}

void SquadMember::setHP(int var){
    this->hp = var;
}

void SquadMember::setDmg(int var){
    this->dmg = var;
}

void SquadMember::setAlive(bool var){
    this->isAlive = var;
}

void SquadMember::dies(){
    this->isAlive = false;
}

SquadMember* SquadMember::clone(){
    return new SquadMember(this->hp, this->dmg, this->name);
}

int SquadMember::takeDamage(int dmg){
    this->hp = this->hp - dmg;
    if(this->hp <= 0){
        this->dies();
    }
    return this->hp;
}