//
// Created by nick on 31.12.20.
//

#include "HikerPlayer.h"

void HikerPlayer::speedup(int speedup, int speedh) {
    int currentSpeed = getSpeed();
    double x = (getOldtimer())*20;
//    std::cout<<x<<std::endl;
    if(speedup==0){
        if(currentSpeed>0){

            currentSpeed -= 1*(getOldtimer()*20);
        } else if(currentSpeed<0){

            currentSpeed += 1*(getOldtimer()*20);
        }
    }
    if(speedup>0 and 0 >currentSpeed){
        currentSpeed +=2*(getOldtimer()*20);
    }
    if(speedup<0 and 0<currentSpeed){
        currentSpeed -=2*(getOldtimer()*20);
    }
    currentSpeed+= speedup*(getOldtimer()*20);
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
        std::shared_ptr<Entity> b = getFact()->createProp(Coordinates(getSize().x - 4, getSize().y - 3), Coordinates(start + length * getMylane(), getPosition().y - 0.5));
        setBalloon(b);
        setLockedtimer(timer+2000000);
        setHasballoon(true);
        return b;
    }
    return nullptr;
}
Coordinates HikerPlayer::update() {
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
    Coordinates pos = getPosition();
    double zer = pos.y-0.01*getSpeed();
    pos.y -= 0.0005*getSpeed()*(getOldtimer()*20);
    if(pos.y>3){
        pos.y = 3;
    }
    setPosition(pos);

    Coordinates toreturn = Coordinates(-move, 0.005 * getSpeed() * (getOldtimer() * 20));
    move = 0;
    return toreturn;
}

void HikerPlayer::fixdebuff(double timer) {
    if(getDebufftimer()<timer){
        setDebuff(false);
        setMaxspeed(getMaxSpeed()*2);
    }
}
