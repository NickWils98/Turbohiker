//
// Created by nick on 31.12.20.
//

#include "HikerPlayer.h"

void HikerPlayer::speedup(int speedup, int speedh) {
    int currentSpeed = getSpeedv();
    if(speedup==0){
        if(currentSpeed>0){

            currentSpeed -= 1*(getDeltaTimer() * 20);
        } else if(currentSpeed<0){

            currentSpeed += 1*(getDeltaTimer() * 20);
        }
    }
    if(speedup>0 and 0 >currentSpeed){
        currentSpeed +=2*(getDeltaTimer() * 20);
    }
    if(speedup<0 and 0<currentSpeed){
        currentSpeed -=2*(getDeltaTimer() * 20);
    }
    currentSpeed+= speedup*(getDeltaTimer() * 20);
    setSpeedv(currentSpeed);
    setSpeedh(speedh);
}

HikerPlayer::HikerPlayer() {

}

std::shared_ptr<Entity> HikerPlayer::shout(double start, double length) {
    if(!isShoutlock()){
        setShoutlock(true);
        std::shared_ptr<Entity> b = getFact()->createProp(Coordinates(getSize().x - 4, getSize().y - 3), Coordinates(start + length *
                                                                                                                                     getMyLane(), getPosition().y - 0.5));
        setTextBubble(b);
        setLockedtimer(getTimer()+2000000);
        setHasTextBubble(true);
        return b;
    }
    return nullptr;
}
Coordinates HikerPlayer::update() {
    if(getSpeedh()>0){
        if(getMyLane() < getLanes()){
            setMyLane(getMyLane() + 1);
            move+= 1;
        }
    } else if(getSpeedh()<0){
        if(getMyLane() != 0){
            setMyLane(getMyLane() - 1);
            move-= 1;
        }
    }
    Coordinates pos = getPosition();
    pos.y -= 0.0005 * getSpeedv() * (getDeltaTimer() * 20);
    if(pos.y>3){
        pos.y = 3;
    }
    setPosition(pos);

    Coordinates toreturn = Coordinates(-move, 0.005 * getSpeedv() * (getDeltaTimer() * 20));
    move = 0;
    return toreturn;
}

void HikerPlayer::removeBuff() {
    if(getBuffedTimer() < getTimer()){
        setBuffed(false);
        setMaxspeed(getMaxSpeed()*2);
    }
}
