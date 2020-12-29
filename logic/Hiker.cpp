//
// Created by nick on 27.12.20.
//

#include "Hiker.h"

void Hiker::updatePlayer(int speedup) {
    speedup*=2;
    float speed = getSpeed();
    if(speedup==0){
        if(speed>0){

            speed /= 1.01;
        } else if(speed<0){

            speed/= 1.01;

        }
    }
    if(speedup>0 and 0 >speed){
        speed /=4;
    }
    if(speedup<0 and 0<speed){
        speed /=4;
    }
    speed+= speedup;
    setSpeed(speed);

}

void Hiker::update() {
    coordinats pos = getPosition();
    pos.y += 0.001*getSpeed();
    setPosition(pos);
}
