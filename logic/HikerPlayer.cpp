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
    currentSpeed+= speedup*2;
    setSpeed(currentSpeed);
    setSpeedh(speedh);
}

HikerPlayer::HikerPlayer() {

}
