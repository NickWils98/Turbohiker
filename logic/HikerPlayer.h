//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_HIKERPLAYER_H
#define TURBOHIKER_HIKERPLAYER_H


#include "Hiker.h"

class HikerPlayer : public Hiker {
public:
    void speedup(int, int) override;

    std::shared_ptr<Entity> shout(double, double) override;

    Coordinates update() override;

    void removeBuff() override;
};


#endif //TURBOHIKER_HIKERPLAYER_H
