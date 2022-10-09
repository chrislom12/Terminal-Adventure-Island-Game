#include "GorillaFactory.h"
#include "Enemy.h"
#include <iostream>
#include <string>
#include <random>


GorillaFactory::~GorillaFactory(){

}

Enemy* GorillaFactory::createEnemy(std::string attack, std::string defense){

    std::string name = getName();
    int dmg =1;

    std::random_device myRandomDevice;
    unsigned seed = myRandomDevice();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(4,12);


    int hp = distribution(generator);
    //std::cout<<hp<<std::endl;

    Gorilla* gorilla = new Gorilla(name, hp, dmg, attack, defense);

    return gorilla;

}
