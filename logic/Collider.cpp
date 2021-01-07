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
    Coordinates otherPosition = other->getPosition();
    Coordinates otherHalfSize = other->GetHalfSize();
    Coordinates thisPosition = first->getPosition();
    Coordinates thisHalfSize = first->GetHalfSize();

    double deltaY = otherPosition.y - thisPosition.y;

    double intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
    return first->getMyLane() == other->getMyLane() && intersectY < 0.0f;
}



bool Collider::checklaneswitch(std::shared_ptr<Entity> first, std::shared_ptr<Entity> other, bool left) {
    Coordinates otherPosition = other->getPosition();
    Coordinates otherHalfSize = other->GetHalfSize();
    Coordinates thisPosition = first->getPosition();
    Coordinates thisHalfSize = first->GetHalfSize();

    double deltaY = otherPosition.y - thisPosition.y;

    double intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if(intersectY < 0.0f){
        if(left){
            if(first->getMyLane() - 1 == other->getMyLane()){
                return false;
            }
        }
        else{
            if(first->getMyLane() + 1 == other->getMyLane()){
                return false;
            }
        }
    }
    return true;
}

std::vector<double> Collider::CollisionDetection(std::shared_ptr<Entity> first, std::shared_ptr<Entity> other, double timer) {

    Coordinates otherPosition = other->getPosition();
    Coordinates otherHalfSize = other->GetHalfSize();
    Coordinates thisPosition = first->getPosition();
    Coordinates thisHalfSize = first->GetHalfSize();

    double deltaY = otherPosition.y - thisPosition.y;

    double intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
    double firstret = 0;
    double otherret = 0;
    if(first->getMyLane() == other->getMyLane() && intersectY < 0.0f){

        firstret = intersectY * (first->getHeaviness() / (other->getHeaviness() + first->getHeaviness()));
        otherret = intersectY * (other->getHeaviness() / (other->getHeaviness() + first->getHeaviness()));
        if(first->isSlowedDown() and !other->isTransparant()){
            other->setBuffed(true);
        }
        if(other->isSlowedDown() and !first->isTransparant()){
            if(!first->isBuffed()) {
                first->setMaxspeed(first->getMaxSpeed()/2);
                first->setBuffed(true);
                first->setDebufftimer(timer+5000000);

            }
        }
        if(first->isTransparant()){

            return {0,0};
        } else if(other->isTransparant()){


            return {0,0};
        }
        if(deltaY > 0.0f){
            otherret *= -1;
            first->Move(0.0f, firstret);
            other->Move(0.0f, otherret);

        } else{
            firstret *= -1;
            first->Move(0.0f, firstret);
            other->Move(0.0f, otherret);

        }

        return {firstret, otherret};
    }


    return {firstret, otherret};
}
