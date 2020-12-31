//
// Created by nick on 30.12.20.
//

#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider() {

}

double Collider::CheckCollision(std::shared_ptr<Entity> first, std::shared_ptr<Entity> other, float push = 1) {
    Entity::coordinats otherPosition = other->getPosition();
    Entity::coordinats otherHalfSize = other->GetHalfSize();
    Entity::coordinats thisPosition = first->getPosition();
    Entity::coordinats thisHalfSize = first->GetHalfSize();

    double deltaY = otherPosition.y - thisPosition.y;

    double intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if(first->getMylane() == other->getMylane() && intersectY < 0.0f){

        push = std::min(std::max(push, 0.0f), 1.0f);

        /*if(intersectX > intersectY){
            if(deltaX > 0.0f){
                first->Move(intersectX * (1.0f - push), 0.0f);
                other->Move(-intersectX * push, 0.0f);

            } else{

                first->Move(-intersectX * (1.0f - push), 0.0f);
                other->Move(intersectX * push, 0.0f);

            }
        } else{*/
        if(deltaY > 0.0f){
            //first->Move(0.0f, intersectY * (1.0f - push));
            other->Move(0.0f, -intersectY * push);

            //object->setHit(0,1);
            //other.object->setHit(0,-1);
        } else{

            //first->Move(0.0f, -intersectY * (push));
            other->Move(0.0f, intersectY * push);

            //object->setHit(0,-1);
            //other.object->setHit(0,1);
        }
    //}

    return intersectY;
    }


    return 0;
}



bool Collider::checklaneswitch(std::shared_ptr<Entity> first, std::shared_ptr<Entity> other, bool left) {
    Entity::coordinats otherPosition = other->getPosition();
    Entity::coordinats otherHalfSize = other->GetHalfSize();
    Entity::coordinats thisPosition = first->getPosition();
    Entity::coordinats thisHalfSize = first->GetHalfSize();

    double deltaY = otherPosition.y - thisPosition.y;

    double intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if(intersectY < 0.0f){
        if(left){
            if(first->getMylane()-1==other->getMylane()){
                return false;
            }
        }
        else{
            if(first->getMylane()+1==other->getMylane()){
                return false;
            }
        }
    }
    return true;
}
