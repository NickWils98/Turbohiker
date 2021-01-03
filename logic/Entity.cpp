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
    return speedv;
}

void Entity::setSpeed(int s) {
    if(maxspeed>=s and -maxspeed/2<=s ){
        speedv = s;
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

int Entity::getSpeedh() const {
    return speedh;
}

void Entity::setSpeedh(int speedh) {
    Entity::speedh = speedh;
}

double Entity::getHeavynes() const {
    return heavynes;
}

void Entity::setHeavynes(double heavynes) {
    Entity::heavynes = heavynes;
}

bool Entity::isGottrough() const {
    return gottrough;
}

void Entity::setGottrough(bool gottrough) {
    Entity::gottrough = gottrough;
}

bool Entity::isSlowdown() const {
    return slowdown;
}

void Entity::setSlowdown(bool slowdown) {
    Entity::slowdown = slowdown;
}

bool Entity::isHasballoon() const {
    return hasballoon;
}

void Entity::setHasballoon(bool hasballoon) {
    Entity::hasballoon = hasballoon;
}

const shared_ptr<Entity> &Entity::getBalloon() const {
    return balloon;
}

void Entity::setBalloon(const shared_ptr<Entity> &balloon) {
    Entity::balloon = balloon;
}
