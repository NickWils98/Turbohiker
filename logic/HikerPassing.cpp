//
// Created by nick on 31.12.20.
//

#include "HikerPassing.h"

HikerPassing::HikerPassing() = default;

void HikerPassing::speedup(int v, int h) {

}

std::shared_ptr<Entity> HikerPassing::shout(double start, double length) {
    std::shared_ptr<RandomeNumber> r = r->getInstance();
    int percent = r->getintpercent();
    if(horizontal){
        if(percent<=25){
            setSpeedh(-1);
        } else if(percent<=50){
            setSpeedh(1);
        }
    } else{
        if(percent<=50){
            if(!isBuffed()) {
                setDebufftimer(getTimer() + 5000000);
                setBuffed(true);
                setMaxspeed(getMaxSpeed()*2);
                setSpeedv(getMaxSpeed());
            }
        }
    }
    return nullptr;
}
Coordinates HikerPassing::update() {
    if(horizontal){
        if(getSpeedh()!=0){
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
            setSpeedh(0);
        }
    } else {

        Coordinates pos = getPosition();
        double zer = pos.y - 0.01 * getSpeedv();
        pos.y -= 0.0005 * getSpeedv() * (getDeltaTimer() * 20);
        setPosition(pos);
    }

    Coordinates toreturn = Coordinates(-move, 0.005 * getSpeedv() * (getDeltaTimer() * 20));
    move = 0;
    return toreturn;
}

void HikerPassing::removeBuff() {
    if(getBuffedTimer() < getTimer()){
        setBuffed(false);
        setMaxspeed(getMaxSpeed()/2);
        setSpeedv(getMaxSpeed());
    }
}

void HikerPassing::setHorizontal(bool horizontal) {
    HikerPassing::horizontal = horizontal;
}
