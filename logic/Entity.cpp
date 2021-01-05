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
void Entity::setPosition(const Entity::coordinats &position) {
    Entity::position = position;
}

double Entity::getMaxSpeed() const {
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

const std::shared_ptr<Entity> &Entity::getBalloon() const {
    return balloon;
}

void Entity::setBalloon(const std::shared_ptr<Entity> &balloon) {
    Entity::balloon = balloon;
}

bool Entity::isDebuff() const {
    return debuff;
}

void Entity::setDebuff(bool debuff) {
    Entity::debuff = debuff;
}

double Entity::getDebufftimer() const {
    return debufftimer;
}

void Entity::setDebufftimer(double debufftimer) {
    Entity::debufftimer = debufftimer;
}

void Entity::setMaxspeed(double maxspeed) {
    Entity::maxspeed = maxspeed;
}

double Entity::getLock() const {
    return lock;
}

void Entity::setLock(double lock) {
    Entity::lock = lock;
}

bool Entity::isLocked() const {
    return locked;
}

void Entity::setLocked(bool locked) {
    Entity::locked = locked;
}

bool Entity::isWannashout() const {
    return wannashout;
}

void Entity::setWannashout(bool wannashout) {
    Entity::wannashout = wannashout;
}

double Entity::getTimer() const {
    return timer;
}

void Entity::setTimer(double timer) {
    Entity::timer = timer;
}

bool Entity::isIsobstacle() const {
    return isobstacle;
}

void Entity::setIsobstacle(bool isobstacle) {
    Entity::isobstacle = isobstacle;
}

double Entity::getOldtimer() const {
    return oldtimer;
}

void Entity::setOldtimer(double oldtimer) {
    Entity::oldtimer = oldtimer;
}

int Entity::getScore() const {
    int x=observer[0]->getScore();
    return x;
}

void Entity::setScore(int score) {
    Entity::score += score;
    subject->setScore(score);
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

void Entity::setEnemy(bool enemy) {
    Entity::enemy = enemy;
}

