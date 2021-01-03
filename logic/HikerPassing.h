//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_HIKERPASSING_H
#define TURBOHIKER_HIKERPASSING_H


#include "Hiker.h"

class HikerPassing : public Hiker {
public:
    HikerPassing();

    void speedup(int, int) override;
    std::shared_ptr<Entity> shout(double, double, double) override;
    tuple<double, double> update();
private:
    int moveing = 0;
    int move = 0;
};


#endif //TURBOHIKER_HIKERPASSING_H
