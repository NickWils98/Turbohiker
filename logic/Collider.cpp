//
// Created by nick on 30.12.20.
//

#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider() {

}

bool Collider::CheckCollision(std::shared_ptr<Entity> first, std::shared_ptr<Entity> other) {
    Entity::coordinats otherPosition = other->getPosition();
    Entity::coordinats otherHalfSize = other->GetHalfSize();
    Entity::coordinats thisPosition = first->getPosition();
    Entity::coordinats thisHalfSize = first->GetHalfSize();

    double deltaY = otherPosition.y - thisPosition.y;

    double intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
    return first->getMylane() == other->getMylane() && intersectY < 0.0f;
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

std::vector<double> Collider::CollisionDetection(std::shared_ptr<Entity> first, std::shared_ptr<Entity> other) {

    Entity::coordinats otherPosition = other->getPosition();
    Entity::coordinats otherHalfSize = other->GetHalfSize();
    Entity::coordinats thisPosition = first->getPosition();
    Entity::coordinats thisHalfSize = first->GetHalfSize();

    double deltaY = otherPosition.y - thisPosition.y;

    double intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
    double firstret = 0;
    double otherret = 0;
    if(CheckCollision(first, other)){

        firstret = intersectY * (first->getHeavynes()/(other->getHeavynes()+first->getHeavynes()));
        otherret = intersectY * (other->getHeavynes()/(other->getHeavynes()+first->getHeavynes()));
        if(first->isGottrough()){
            other->setSpeed(10);
        }
        if(other->isGottrough()){
            first->setSpeed(10);
        }
        if(first->isGottrough()){

            return {0,0};
        } else if(other->isGottrough()){


            return {0,0};
        }
        if(deltaY > 0.0f){
            otherret *= -1;
            first->Move(0.0f, firstret);
            other->Move(0.0f, otherret);

            //object->setHit(0,1);
            //other.object->setHit(0,-1);
        } else{
            firstret *= -1;
            first->Move(0.0f, firstret);
            other->Move(0.0f, otherret);

            //object->setHit(0,-1);
            //other.object->setHit(0,1);
        }
        //}

        return {firstret, otherret};
    }


    return {firstret, otherret};
    return std::vector<double>();
}
