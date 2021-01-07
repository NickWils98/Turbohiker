//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_LANES_H
#define TURBOHIKER_LANES_H


#include "Entity.h"

class Lanes : public Entity {
public:
    void render() override {};

    Coordinates update() override { return Coordinates(0, 0); };

    bool updateVisuals(Coordinates s) override {};

    virtual void movetoview(double) = 0;

    void speedup(int, int) override {};

    void fixdebuff(double) override {};

    std::shared_ptr<Entity> shout(double d, double e, double g) override {
        return nullptr;
    }
};


#endif //TURBOHIKER_LANES_H
