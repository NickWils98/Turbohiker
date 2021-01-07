//
// Created by nick on 27.12.20.
//

#include "Entity.h"
const Coordinates &Entity::getPosition() const {
    return position;
}

void Entity::setPosition(double x, double y) {
    position.x = x;
    position.y = y;
}

const Coordinates &Entity::getSize() const {
    return size;
}

void Entity::setSize(double x, double y) {
    size.x = x;
    size.y = y;
}

double Entity::getSpeed() const {
    return speedv;
}

void Entity::setSpeed(double s) {
    if(maxspeed>=s and -maxspeed/2<=s ){
        speedv = s;
    } else{
        if( maxspeed<s){
            speedv = maxspeed;
        } else{
            speedv = -maxspeed/2;
        }
    }
}
void Entity::setPosition(const Coordinates &p) {
    Entity::position = p;
}

double Entity::getMaxSpeed() const {
    return maxspeed;
}

Coordinates Entity::GetHalfSize() const {
    Coordinates halfsize{getSize().x / 2.0f, getSize().y / 2.0f};
    return halfsize;
}

int Entity::getMylane() const {
    return mylane;
}

void Entity::setMylane(int l) {
    Entity::mylane = l;
}

int Entity::getSpeedh() const {
    return speedh;
}

void Entity::setSpeedh(int s) {
    Entity::speedh = s;
}

double Entity::getHeavynes() const {
    return heavynes;
}

void Entity::setHeavynes(double h) {
    Entity::heavynes = h;
}

bool Entity::isGottrough() const {
    return gottrough;
}

void Entity::setGottrough(bool g) {
    Entity::gottrough = g;
}

bool Entity::isSlowdown() const {
    return slowdown;
}

void Entity::setSlowdown(bool s) {
    Entity::slowdown = s;
}

bool Entity::isHasballoon() const {
    return hasballoon;
}

void Entity::setHasballoon(bool b) {
    Entity::hasballoon = b;
}

const std::shared_ptr<Entity> &Entity::getBalloon() const {
    return balloon;
}

void Entity::setBalloon(const std::shared_ptr<Entity> &b) {
    Entity::balloon = b;
}

bool Entity::isDebuff() const {
    return debuff;
}

void Entity::setDebuff(bool b) {
    Entity::debuff = b;
}

double Entity::getDebufftimer() const {
    return debufftimer;
}

void Entity::setDebufftimer(double bt) {
    Entity::debufftimer = bt;
}

void Entity::setMaxspeed(double ms) {
    Entity::maxspeed = ms;
}

double Entity::getLock() const {
    return lock;
}

void Entity::setLock(double l) {
    Entity::lock = l;
}

bool Entity::isLocked() const {
    return locked;
}

void Entity::setLocked(bool l) {
    Entity::locked = l;
}

bool Entity::isWannashout() const {
    return wannashout;
}

void Entity::setWannashout(bool ws) {
    Entity::wannashout = ws;
}

double Entity::getTimer() const {
    return timer;
}

void Entity::setTimer(double t) {
    Entity::timer = t;
}

bool Entity::isIsobstacle() const {
    return isobstacle;
}

void Entity::setIsobstacle(bool o) {
    Entity::isobstacle = o;
}

double Entity::getOldtimer() const {
    return oldtimer;
}

void Entity::setOldtimer(double ot) {
    Entity::oldtimer = ot;
}

int Entity::getScore() const {
    int x=observer[0]->getScore();
    return x;
}

void Entity::setScore(int s) {
    subject->setScore(s);
}

const std::string &Entity::getScoring() const {
    return scoring;
}

void Entity::setScoring(const int &s) {
    std::string s_text = std::to_string(s);
    Entity::scoring = s_text;
}

bool Entity::isEnemy() const {
    return enemy;
}

void Entity::setEnemy(bool e) {
    Entity::enemy = e;
}

