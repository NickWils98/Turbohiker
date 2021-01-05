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
            setWannashout(true);
        } else if(speedh == 2){
            if(precent>99){
                setWannashout(true);

            } else {
                if(isLocked()) {
                    setWannashout(true);
                } else{
                    //player->updatePlayerh(speedh);
                    setLock(getTimer() + 600000);
                    setLocked(true);
                    setspeedh = -1;
                }
            }

        } else if(speedh == 1){
            if(precent>99){
                setWannashout(true);
            } else {
                if(isLocked()) {
                    setWannashout(true);
                } else{
                    //player->updatePlayerh(speedh);
                    setLock(getTimer() + 600000);
                    setLocked(true);
                    setspeedh = 1;
                }
            }
        } else{
            int x = (precent<=40) ? 1 : -1;
            if(precent>99){
                setWannashout(true);

            } else {
                if(isLocked()) {
                    setWannashout(true);
                } else{
                    //player->updatePlayerh(speedh);
                    setLock(getTimer() + 600000);
                    setLocked(true);
                    setspeedh = x;
                }
            }
        }
    }
    int speedup = 1;
    int currentSpeed = getSpeed();

    if(speedup>0 and 0 >currentSpeed){
        currentSpeed +=2*(getOldtimer()*20);
    }
    if(speedup<0 and 0<currentSpeed){
        currentSpeed -=2*(getOldtimer()*20);
    }
    currentSpeed+= speedup*(getOldtimer()*20);
    setSpeed(currentSpeed);
    setSpeedh(setspeedh);
}

std::shared_ptr<Entity> HikerEnemy::shout(double timer, double start, double length) {
//    if(timer>lockedtimer){
//        shoutlock = false;
//
//    }
    if(!isShoutlock()){
        setShoutlock(true);
        std::shared_ptr<Entity> b = getFact()->createProp(std::tuple<double, double>(getSize().x-4, getSize().y-3), std::tuple<double, double>(start+length*getMylane(), getPosition().y-0.5));
        setBalloon(b);
        setLockedtimer(timer+2000000);
        setHasballoon(true);
        return b;
    }
    return nullptr;
}
std::tuple<double, double> HikerEnemy::update() {
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
    pos.y -= 0.0005*getSpeed()*(getOldtimer()*20);
    setPosition(pos);
    std::tuple<double, double> toreturn = std::make_tuple(-move, 0.005*getSpeed()*(getOldtimer()*20));
    move = 0;
    return toreturn;
}

void HikerEnemy::fixdebuff(double timer) {
    if(getDebufftimer()<timer){
        setDebuff(false);
        setMaxspeed(getMaxSpeed()*2);
    }

}
