//
// Created by nick on 31.12.20.
//

#include "HikerEnemy.h"

HikerEnemy::HikerEnemy() {}

void HikerEnemy::speedup(int speedv, int speedh) {
//  speedv 1 if obstacle in front else 0
//  speedh 3 if obstacle left and right, 2 if obstacle left, 1 if obstacle right else 0
    std::shared_ptr<RandomeNumber>r = r->getInstance();
    int precent = r->getintpercent();
    int setspeedh = 0;
    if(speedv==1){
        if(speedh == 3){
            setWantToShout(true);
        } else if(speedh == 2){
            if(precent>99){
                setWantToShout(true);

            } else {
                if(isTimeLocked()) {
                    setWantToShout(true);
                } else{
                    setTimeLock(getTimer() + 600000);
                    setTimeLocked(true);
                    setspeedh = -1;
                }
            }

        } else if(speedh == 1){
            if(precent>99){
                setWantToShout(true);
            } else {
                if(isTimeLocked()) {
                    setWantToShout(true);
                } else{
                    setTimeLock(getTimer() + 600000);
                    setTimeLocked(true);
                    setspeedh = 1;
                }
            }
        } else{
            int x = (precent<=40) ? 1 : -1;
            if(precent>99){
                setWantToShout(true);

            } else {
                if(isTimeLocked()) {
                    setWantToShout(true);
                } else{
                    setTimeLock(getTimer() + 600000);
                    setTimeLocked(true);
                    setspeedh = x;
                }
            }
        }
    }
    int speedup = 1;
    int currentSpeed = getSpeedv();

    if(speedup>0 and 0 >currentSpeed){
        currentSpeed +=2*(getDeltaTimer() * 20);
    }
    if(speedup<0 and 0<currentSpeed){
        currentSpeed -=2*(getDeltaTimer() * 20);
    }
    currentSpeed+= speedup*(getDeltaTimer() * 20);
    setSpeedv(currentSpeed);
    setSpeedh(setspeedh);
}

std::shared_ptr<Entity> HikerEnemy::shout(double start, double length) {
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
Coordinates HikerEnemy::update() {
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
    setPosition(pos);
    Coordinates toreturn = Coordinates(-move, 0.005 * getSpeedv() * (getDeltaTimer() * 20));
    move = 0;
    return toreturn;
}

void HikerEnemy::removeBuff() {
    if(getBuffedTimer() < getTimer()){
        setBuffed(false);
        setMaxspeed(getMaxSpeed()*2);
    }
}
