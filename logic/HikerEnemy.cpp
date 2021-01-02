//
// Created by nick on 31.12.20.
//

#include "HikerEnemy.h"

HikerEnemy::HikerEnemy() {}

void HikerEnemy::speedup(int speedup, int h) {
    speedup = 1;
    int currentSpeed = getSpeed();

    if(speedup>0 and 0 >currentSpeed){
        currentSpeed +=2;
    }
    if(speedup<0 and 0<currentSpeed){
        currentSpeed -=2;
    }
    currentSpeed+= speedup*2;
    setSpeed(currentSpeed);
}
