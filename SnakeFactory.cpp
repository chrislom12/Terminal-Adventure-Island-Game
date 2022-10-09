#include "SnakeFactory.h"
#include "Enemy.h"
#include <iostream>
#include <string>
#include <random>


SnakeFactory::~SnakeFactory(){

}

Enemy* SnakeFactory::createEnemy(std::string attack, std::string defense){

    std::string name = getName();
    int dmg =2;

    std::random_device myRandomDevice;
    unsigned seed = myRandomDevice();
    std::default_random_engine generator(seed);
    std::normal_distribution<double> distribution(6.0,1.0);

    int hp = (int) distribution(generator);
    //std::cout<<hp<<std::endl;

    Snake* snakeObj = new Snake(name, hp, dmg, attack, defense);

    return snakeObj;

}
