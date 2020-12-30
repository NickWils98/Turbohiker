//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_LANES_H
#define TURBOHIKER_LANES_H


#include "Entity.h"

class Lanes : public Entity{
public:
    void render() override{};
    tuple<double, double> update() override{return make_tuple(0,0);};
    void updateVisuals(std::tuple<int, int> s)override{};
    virtual void movetoview(double) = 0;
};


#endif //TURBOHIKER_LANES_H
