//
// Created by nick on 27.12.20.
//

#include "Entity.h"
const Entity::coordinats &Entity::getPosition() const {
    return position;
}

void Entity::setPosition(double x, double y) {
    position.x = x;
    position.y = y;
}

const Entity::coordinats &Entity::getSize() const {
    return size;
}

void Entity::setSize(double x, double y) {
    size.x = x;
    size.y = y;
}

int Entity::getSpeed() const {
    return speed;
}

void Entity::setSpeed(int s) {
    if(maxspeed>=s and -maxspeed/2<=s ){
        speed = s;
    }
}
void Entity::setPosition(const Entity::coordinats &position) {
    Entity::position = position;
}

int Entity::getMaxSpeed() const {
    return maxspeed;
}

Entity::coordinats Entity::GetHalfSize() {
    coordinats halfsize;
    halfsize.x = getSize().x/2.0f;
    halfsize.y = getSize().y/2.0f;

    return halfsize;
}

int Entity::getMylane() const {
    return mylane;
}

void Entity::setMylane(int mylane) {
    Entity::mylane = mylane;
}