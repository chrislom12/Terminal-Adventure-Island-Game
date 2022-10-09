#include "Enemy.h"

Enemy::Enemy(){

}

Enemy::~Enemy(){

}

void Enemy::attack(SquadMember* z){

    while (z->getHP()>0 && z->getAlive())//and is alive
        {
            if(hitSquadMember(z)){
                z->dies();
                celebrate();
                break;
            }
            else{
                if(getHit(z)){
                    die();
                    break;
                }
            }
        }
}

bool Enemy::hitSquadMember(SquadMember* z){
    return true;
}

void celebrate(){
    
}

bool getHit(SquadMember* z){
    return true;
}

void die(){
    
}




