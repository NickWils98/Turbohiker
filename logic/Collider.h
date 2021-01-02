//
// Created by nick on 30.12.20.
//

#ifndef TURBOHIKER_COLLIDER_H
#define TURBOHIKER_COLLIDER_H


#include <memory>
#include "Hiker.h"

class Collider {
public:
    explicit Collider();
    ~Collider();

    //void Move(float dx, float dy){setPosition(getPosition().x+dx, getPosition().y+dy);};

    std::vector<double> CollisionDetection(std::shared_ptr<Entity>, std::shared_ptr<Entity>);
    bool checklaneswitch(std::shared_ptr<Entity> first, std::shared_ptr<Entity> other, bool);
    bool CheckCollision(std::shared_ptr<Entity> first, std::shared_ptr<Entity> other);





};


#endif //TURBOHIKER_COLLIDER_H
