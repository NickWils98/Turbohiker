//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_HIKERPLAYER_H
#define TURBOHIKER_HIKERPLAYER_H


#include "Hiker.h"

class HikerPlayer : public Hiker {
public:
    HikerPlayer();

    void speedup(int, int) override;
    std::shared_ptr<Entity> shout(double, double, double) override;
    tuple<double, double> update() override;

private:
    int move = 0;
};


#endif //TURBOHIKER_HIKERPLAYER_H
