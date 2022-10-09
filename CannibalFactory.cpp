#include "CannibalFactory.h"
#include "Enemy.h"
#include <iostream>
#include <string>
#include <random>


CannibalFactory::~CannibalFactory(){

}

Enemy* CannibalFactory::createEnemy(std::string attack, std::string defense){

    std::string name = getName();
    int dmg =8;

    std::random_device myRandomDevice;
    unsigned seed = myRandomDevice();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(8,30);

    int hp = distribution(generator);
    //std::cout<<hp<<std::endl;

    Cannibal* cannibal = new Cannibal(name, hp, dmg, attack, defense);

    return cannibal;

}
