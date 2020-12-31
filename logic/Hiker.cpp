//
// Created by nick on 27.12.20.
//

#include "Hiker.h"

void Hiker::updatePlayerv(int speedup) {
    //speedup*=2;
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
    currentSpeed+= speedup*2;
    setSpeed(currentSpeed);

}
void Hiker::updatePlayerh(int speedh) {
    if(speedh>0){
        if(getMylane()<lanes){
            setMylane(getMylane()+1);
            move+= 1;
        }
    } else if(speedh<0){
        if(getMylane()!=0){
            setMylane(getMylane()-1);
            move-= 1;
        }
    }

}
tuple<double, double> Hiker::update() {
    if(getSpeed()>0){
        int x = 5;
    }
    coordinats pos = getPosition();
    double zer = pos.y-0.01*getSpeed();
    pos.y -= 0.005*getSpeed();
    setPosition(pos);
    tuple<double, double> toreturn = make_tuple(-move, 0.005*getSpeed());
    move = 0;
    return toreturn;
}

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




