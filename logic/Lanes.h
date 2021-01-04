//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_LANES_H
#define TURBOHIKER_LANES_H


#include "Entity.h"

class Lanes : public Entity{
public:
    void render() override{};
    std::tuple<double, double> update() override{return std::make_tuple(0,0);};
    bool updateVisuals(std::tuple<int, int> s)override{};
    virtual void movetoview(double) = 0;
    void speedup(int, int) override{};
    void fixdebuff(double) override{};

    std::shared_ptr<Entity> shout(double d, double e, double g) override {
        return nullptr;
    }
};


#endif //TURBOHIKER_LANES_H
