//
// Created by nick on 31.12.20.
//

#include "HikerPlayer.h"

void HikerPlayer::speedup(int speedup, int speedh) {
    int currentSpeed = getSpeed();

    if(speedup==0){
        if(currentSpeed>0){

            currentSpeed -= 1;
        } else if(currentSpeed<0){

            currentSpeed += 1;
        }
    }
    if(speedup>0 and 0 >currentSpeed){
        currentSpeed +=2;
    }
    if(speedup<0 and 0<currentSpeed){
        currentSpeed -=2;
    }
    currentSpeed+= speedup;
    setSpeed(currentSpeed);
    setSpeedh(speedh);
}

HikerPlayer::HikerPlayer() {

}

std::shared_ptr<Entity> HikerPlayer::shout(double timer, double start, double length) {
//    if(timer>lockedtimer){
//        shoutlock = false;
//
//    }
    if(!isShoutlock()){
        setShoutlock(true);
        std::shared_ptr<Entity> b = getFact()->createProp(tuple<double, double>(getSize().x-4, getSize().y-3), tuple<double, double>(start+length*getMylane(), getPosition().y-0.5));
        setBalloon(b);
        setLockedtimer(timer+1000000);
        setHasballoon(true);
        return b;
    }
    return nullptr;
}
tuple<double, double> HikerPlayer::update() {
    if(getSpeedh()>0){
        if(getMylane()<getLanes()){
            setMylane(getMylane()+1);
            move+= 1;
        }
    } else if(getSpeedh()<0){
        if(getMylane()!=0){
            setMylane(getMylane()-1);
            move-= 1;
        }
    }

    if(getSpeed()>0){
        int x = 5;
    }
    coordinats pos = getPosition();
    double zer = pos.y-0.01*getSpeed();
    pos.y -= 0.0005*getSpeed();
    setPosition(pos);
    tuple<double, double> toreturn = make_tuple(-move, 0.005*getSpeed());
    move = 0;
    return toreturn;
}