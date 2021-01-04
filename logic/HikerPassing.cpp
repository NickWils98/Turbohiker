//
// Created by nick on 31.12.20.
//

#include "HikerPassing.h"

HikerPassing::HikerPassing() {}

void HikerPassing::speedup(int v, int h) {

}

std::shared_ptr<Entity> HikerPassing::shout(double timer, double start, double length) {
//    if(timer>lockedtimer){
//        shoutlock = false;
//
//    }
    RandomeNumber* r = r->getInstance();
    int percent = r->getintpercent();
    if(isHorizontal()){
        if(percent<=25){
            setSpeedh(-1);
        } else if(percent<=50){
            setSpeedh(1);
        }
    } else{
        if(percent<=50){
            if(!isDebuff()) {
                setDebufftimer(timer + 5000000);
                setDebuff(true);
                setMaxspeed(getMaxSpeed()*2);
                setSpeed(getMaxSpeed());
            }
        }
    }
    return nullptr;
}
std::tuple<double, double> HikerPassing::update() {
    if(isHorizontal()){
        if(getSpeedh()!=0){
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
            setSpeedh(0);
        }
    } else {

        coordinats pos = getPosition();
        double zer = pos.y - 0.01 * getSpeed();
        pos.y -= 0.0005 * getSpeed()*(getOldtimer()*20);
        setPosition(pos);
    }

    std::tuple<double, double> toreturn = std::make_tuple(-move, 0.005*getSpeed()*(getOldtimer()*20));
    move = 0;
    return toreturn;
}

void HikerPassing::fixdebuff(double timer) {
    if(getDebufftimer()<timer){
        setDebuff(false);
        setMaxspeed(getMaxSpeed()/2);
        setSpeed(getMaxSpeed());
    }
}
