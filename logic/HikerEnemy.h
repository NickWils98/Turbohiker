//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_HIKERENEMY_H
#define TURBOHIKER_HIKERENEMY_H


#include "Hiker.h"

class HikerEnemy : public Hiker {
public:
    HikerEnemy();

    void speedup(int, int) override;
    std::shared_ptr<Entity> shout(double, double, double) override;
    std::tuple<double, double> update() override;

    void fixdebuff(double d) override;

private:
    int move = 0;
};


#endif //TURBOHIKER_HIKERENEMY_H
