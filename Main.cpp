#include "SquadMember.h"
#include "Enemy.h"
#include "EnemyFactory.h"
#include "SnakeFactory.h"
#include "GorillaFactory.h"
#include "JaguarFactory.h"
#include "CannibalFactory.h"
#include <iostream>
#include <random>

void testSquadMember();
void testEnemy();
void startGame();
void printMenu();
void printTitle();
std::string getMenuInput();
std::string getArenaInput();

bool validateMenuInput(std::string input);
bool validateArenaInput(std::string input);

void arenaBattle();
SquadMember* createCharacter();
void quit();
bool quitGame = false;
SquadMember* player = new SquadMember(30, 10, "John Doe");

int main(){

    //testSquadMember();
    //testEnemy();
    startGame();
    
    
    return 0;
}

void testSquadMember(){
    std::cout<<"TESTING SQUADMEMBER\n=========================\n"<<std::endl;

    SquadMember* member = new SquadMember(100, 10, "John");
    std::cout << member->getHP() << std::endl;
    std::cout << member->getDmg() << std::endl;
    std::cout << member->getName() << std::endl;
    std::cout << member->getAlive() << std::endl;
    member->setHP(50);
    std::cout << member->getHP() << std::endl;
    member->setDmg(20);
    std::cout << member->getDmg() << std::endl;
    member->dies();
    std::cout << member->getAlive() << std::endl;
    member->setAlive(true);
    std::cout << member->getAlive() << std::endl;
    SquadMember* member2 = member->clone();
    std::cout << member2->getHP() << std::endl;
    std::cout << member2->getDmg() << std::endl;
    std::cout << member2->getName() << std::endl;
    std::cout << member2->getAlive() << std::endl;
    delete member;
    delete member2;

    std::cout<<std::endl;
}

void testEnemy(){

    std::cout<<"TESTING ENEMIES AND FIGHTING\n=========================\n"<<std::endl;
    
    EnemyFactory* factoryS = new SnakeFactory();
    Enemy* snake1 = factoryS->createEnemy("Fang", "Tail Jump");
    std::cout<<"Snake Name: "<<snake1->getName()<<std::endl;
    std::cout<<"Snake HP: "<<snake1->getHp()<<std::endl;

    EnemyFactory* factoryG = new GorillaFactory();
    Enemy* gorilla1 = factoryG->createEnemy("Bash", "Arm Block");
    std::cout<<"Gorilla Name: "<<gorilla1->getName()<<std::endl;
    std::cout<<"Gorilla HP: "<<gorilla1->getHp()<<std::endl;
   
    EnemyFactory* factoryJ = new JaguarFactory();
    Enemy* jaguar1 = factoryJ->createEnemy("Paw of Death", "Tail of Steel");
    std::cout<<"Jaguar Name: "<<jaguar1->getName()<<std::endl;
    std::cout<<"Jaguar HP: "<<jaguar1->getHp()<<std::endl;
   
    EnemyFactory* factoryC = new CannibalFactory();
    Enemy* cannibal1 = factoryC->createEnemy("Desperate Punches", "Beg for Mercy");
    std::cout<<"Cannibal Name: "<<cannibal1->getName()<<std::endl;
    std::cout<<"Cannibal HP: "<<cannibal1->getHp()<<std::endl;
    
    SquadMember* member = new SquadMember(20, 6, "John Doe");

    std::cout<<"\nNow Fighting Snake:\n";
    std::cout<<member->getName()<<" hp: "<<member->getHP()<<std::endl;
    snake1->attack(member);

    std::cout<<"\nNow Fighting Gorilla:\n";
    std::cout<<member->getName()<<" hp: "<<member->getHP()<<std::endl;
    gorilla1->attack(member);

    std::cout<<"\nNow Fighting Jaguar:\n";
    std::cout<<member->getName()<<" hp: "<<member->getHP()<<std::endl;
    jaguar1->attack(member);

    std::cout<<"\nNow Fighting Cannibal:\n";
    std::cout<<member->getName()<<" hp: "<<member->getHP()<<std::endl;
    cannibal1->attack(member);

    std::cout<<"\nAfter Fight:\n";
    std::cout<<member->getName()<<" hp: "<<member->getHP()<<std::endl;
 
    delete snake1;
    delete gorilla1;
    delete jaguar1;
    delete cannibal1;
    delete factoryS;
    delete factoryG;
    delete factoryJ;
    delete factoryC;
    delete member;

}

void startGame(){
    srand(time(0));
    static std::default_random_engine generator(time(NULL));
    
    
    while(!quitGame){
        printTitle();
        printMenu();
        std::string input = getMenuInput();

        if(input == "1"){
            arenaBattle();
        }
        else if(input == "2"){
            player = createCharacter();
        }
        else if(input == "3"){
            quit();
        }
    }
    
    



}

void printTitle(){
    std::cout<<"==================================================================================="<<std::endl;
    std::cout<<"==================================================================================="<<std::endl;
    std::cout<<"              _                 _                    _____     _                 _ "<<std::endl;
    std::cout<<"     /\\      | |               | |                  |_   _|   | |               | |"<<std::endl;
    std::cout<<"    /  \\   __| |_   _____ _ __ | |_ _   _ _ __ ___    | |  ___| | __ _ _ __   __| |"<<std::endl;
    std::cout<<"   / /\\ \\ / _` \\ \\ / / _ \\ '_ \\| __| | | | '__/ _ \\   | | / __| |/ _` | '_ \\ / _` |"<<std::endl;
    std::cout<<"  / ____ \\ (_| |\\ V /  __/ | | | |_| |_| | | |  __/  _| |_\\__ \\ | (_| | | | | (_| |"<<std::endl;
    std::cout<<" /_/    \\_\\__,_| \\_/ \\___|_| |_|\\__|\\__,_|_|  \\___| |_____|___/_|\\__,_|_| |_|\\__,_|"<<std::endl;
    std::cout<<"                                                                                   "<<std::endl;
    std::cout<<"==================================================================================="<<std::endl;
    std::cout<<"==================================================================================="<<std::endl;    
}

void printMenu(){
    
    std::cout<<"Menu:\n========\n1. Arena Battle\n2. Create Character\n3. Quit"<<std::endl;
}

std::string getMenuInput(){

    std::cout << "\nType a Number: ";
    std::string input;
    std::cin>>input;
    
    while(!validateMenuInput(input)){
        std::cout << "--- Invalid Input ---\nType a Number: ";
        std::cin>>input;
    }
    std::cout << "\n";

    return input;
}

bool validateMenuInput(std::string input){
    if(input == "1" || input == "2" || input == "3"){
        return true;
    }
    else{
        return false;
    }
}

std::string getArenaInput(){

    std::cout << "\nType a Number: ";
    std::string input;
    std::cin>>input;
    
    while(!validateArenaInput(input)){
        std::cout << "--- Invalid Input ---\nType a Number: ";
        std::cin>>input;
    }
    std::cout << "\n";

    return input;
}

bool validateArenaInput(std::string input){
    if(input == "1" || input == "2" || input == "3" || input == "4" || input == "5"){
        return true;
    }
    else{
        return false;
    }
}

void arenaBattle(){
    EnemyFactory* factoryS = new SnakeFactory();
    EnemyFactory* factoryG = new GorillaFactory();
    EnemyFactory* factoryJ = new JaguarFactory();
    EnemyFactory* factoryC = new CannibalFactory();

    std::cout<<"=================\nARENA BATTLE\n=================\n"<<std::endl;
    std::cout<<"You enter a vast and old arena - shackled in chains. Hoards of angry animals cheering and booing in a sea of noise. They unchain you and present four different warriors before you, make your choice - it might be the last choice you make.\n"<<std::endl;

    std::cout<<"\nChoose your opponent:\n1. Snake\n2. Gorilla\n3. Jaguar\n4. Cannibal\n5. Quit Game"<<std::endl;
    std::string input = getArenaInput();

    while(input != "5"){
        Enemy* enemy;
        if(input == "1"){
            enemy = factoryS->createEnemy("Fang", "Tail Jump");

        }
        else if(input == "2"){
            enemy = factoryG->createEnemy("Bash", "Arm Block");

        }
        else if(input == "3"){
            enemy = factoryJ->createEnemy("Paw of Death", "Tail of Steel");

        }
        else if(input == "4"){
            enemy = factoryC->createEnemy("Desperate Punches", "Beg for Mercy");

        }
        std::cout<<"\nNow Fighting "<<enemy->getName()<<"\n-------------------------\n\n";
        std::cout<<"("<<player->getName()<<" HP: "<<player->getHP()<<")"<<std::endl;
        enemy->attack(player);
        std::cout<<"("<<player->getName()<<" HP: "<<player->getHP()<<")"<<std::endl;
        if(player->getHP() <= 0){
            std::cout<<"\nYou have been defeated in the Arena!\n"<<std::endl;
            delete enemy;
            break;
        }
        

        std::cout<<"\nChoose your opponent:\n1. Snake\n2. Gorilla\n3. Jaguar\n4. Cannibal\n5. Quit Game"<<std::endl;
        input = getArenaInput();
        
        
    }

    startGame();
    
   
    
}

SquadMember* createCharacter(){
     std::cout<<"=================\nCreate Character\n================="<<std::endl;
    std::cin.ignore(1,'\n');
    std::string name;
    std::cout << "\nEnter Name: ";
    std::getline(std::cin,name);
    std::cout << "Enter HP: ";
    std::string hp;
    std::cin>>hp;
    std::cout << "Enter Damage: ";
    std::string dmg;
    std::cin>>dmg;

    SquadMember* member = new SquadMember(std::stoi(hp), std::stoi(dmg), name);

     std::cout<<std::endl;
    return member;

}

void quit(){
     std::cout<<"======================================\nOnly Losers Quit, but Goodbye for Now!\n======================================\n"<<std::endl;
    quitGame = true;
}