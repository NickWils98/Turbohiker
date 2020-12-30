//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H
#include <memory>
#include <tuple>
#include "ColorLogic.h"
#include "../Transformation.h"

class Entity {
public:
    struct coordinats {
        double x = 0;
        double y = 0;
    };
    const coordinats &getPosition() const;
    const coordinats &getSize() const;
    void setPosition(double x, double y);
    void setPosition(const coordinats &position);
    void setSize(double x, double y);
    int getSpeed() const;
    int getMaxSpeed() const;
    void setSpeed(int speed);
    virtual double helpcout(){return 0;};
    Entity() = default;

    virtual ~Entity() = default;

    virtual void render() = 0;
    virtual tuple<double, double> update() = 0;
    virtual void updateVisuals(std::tuple<int, int> s) = 0;
    virtual void movetoview(double) = 0;

private:
    coordinats position;
    coordinats size;
    int maxspeed = 20;
    int speed = 0;

};


#endif //TURBOHIKER_ENTITY_H
