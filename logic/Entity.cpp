//
// Created by nick on 27.12.20.
//

#include "Entity.h"
const Entity::coordinats &Entity::getPosition() const {
    return position;
}

void Entity::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

const Entity::coordinats &Entity::getSize() const {
    return size;
}

void Entity::setSize(float x, float y) {
    size.x = x;
    size.y = y;
}

float Entity::getSpeed() const {
    return speed;
}

void Entity::setSpeed(float s) {
    if(maxspeed/2>=s and -maxspeed<=s ){
        speed = s;
    }
}
void Entity::setPosition(const Entity::coordinats &position) {
    Entity::position = position;
}