#include "JaguarFactory.h"
#include "Enemy.h"
#include <iostream>
#include <string>
#include <random>


JaguarFactory::~JaguarFactory(){

}

Enemy* JaguarFactory::createEnemy(std::string attack, std::string defense){

    std::string name = getName();
    int dmg =4;

    std::random_device myRandomDevice;
    unsigned seed = myRandomDevice();
    std::default_random_engine generator(seed);
    std::normal_distribution<double> distribution(10.0,3.0);

    int hp = (int) distribution(generator);
    //std::cout<<hp<<std::endl;

    Jaguar* jaguar = new Jaguar(name, hp, dmg, attack, defense);

    return jaguar;

}
