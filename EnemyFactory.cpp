#include "EnemyFactory.h"

EnemyFactory::EnemyFactory()
{

}

std::string EnemyFactory::getName()
{
    
    int randomNumber1 = rand() % 14;
    //std::cout<<randomNumber1<<std::endl;
    int randomNumber2 = rand() % 14;
    //std::cout<<randomNumber2<<std::endl;

    std::string name = "";

    name = names[randomNumber1] + " " + surnames[randomNumber2];

    return name;
}

/* Enemy* EnemyFactory::createEnemy(std::string attack, std::string defense){
    
} */


