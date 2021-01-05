//
// Created by nick on 27.12.20.
//

#include "Hiker.h"

//void Hiker::updatePlayerv(int speedup) {
//    //speedup*=2;
//    int currentSpeed = getSpeed();
//
//    if(speedup==0){
//        if(currentSpeed>0){
//
//            currentSpeed -= 0.00001;
//        } else if(currentSpeed<0){
//
//            currentSpeed += 0.000001;
//        }
//    }
//    if(speedup>0 and 0 >currentSpeed){
//        currentSpeed +=2;
//    }
//    if(speedup<0 and 0<currentSpeed){
//        currentSpeed -=2;
//    }
//    currentSpeed+= speedup*0.02;
//    setSpeed(currentSpeed);
//
//}
//void Hiker::updatePlayerh(int speedh) {
//    if(speedh>0){
//        if(getMylane()<lanes){
//            setMylane(getMylane()+1);
//            move+= 1;
//        }
//    } else if(speedh<0){
//        if(getMylane()!=0){
//            setMylane(getMylane()-1);
//            move-= 1;
//        }
//    }
//
//}


void Hiker::movetoview(double moved) {
    if(moved!=0){
        int f = 8;
    }
    coordinats pos = getPosition();
    pos.y -= moved;
    //pos.y = 0;
    setPosition(pos);
}

int Hiker::getLanes() const {
    return lanes;
}

void Hiker::setLanes(int lanes) {
    Hiker::lanes = lanes;
}



std::shared_ptr<Entity> Hiker::remove_shout(double timer) {
    if(shoutlock) {
        if (timer > lockedtimer) {
            shoutlock = false;
            std::shared_ptr<Entity> b = getBalloon();
            setBalloon(nullptr);
            setHasballoon(false);
            return b;

        }
    }

    return nullptr;
}

void Hiker::setFact(const std::shared_ptr<FactoryLines> &fact) {
    Hiker::fact = fact;
}

const std::shared_ptr<FactoryLines> &Hiker::getFact() const {
    return fact;
}

bool Hiker::isShoutlock() const {
    return shoutlock;
}

void Hiker::setShoutlock(bool shoutlock) {
    Hiker::shoutlock = shoutlock;
}

double Hiker::getLockedtimer() const {
    return lockedtimer;
}

void Hiker::setLockedtimer(double lockedtimer) {
    Hiker::lockedtimer = lockedtimer;
}

bool Hiker::isHorizontal() const {
    return horizontal;
}

void Hiker::setHorizontal(bool horizontal) {
    Hiker::horizontal = horizontal;
}

void Hiker::setScoretext(const std::shared_ptr<Entity> &scoretext) {
    Hiker::scoretext = scoretext;
}

const std::shared_ptr<Entity> &Hiker::getScoretext() const {
    return scoretext;
}




