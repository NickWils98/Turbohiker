//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H
#include <memory>
#include <tuple>
#include "ColorLogic.h"
#include "../Transformation.h"
#include "../RandomeNumber.h"

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
    coordinats GetHalfSize();
    void Move(float dx, float dy){setPosition(getPosition().x+dx, getPosition().y+dy);};


    virtual ~Entity() = default;

    virtual void render() = 0;
    virtual tuple<double, double> update() = 0;
    virtual void updateVisuals(std::tuple<int, int> s) = 0;
    virtual void movetoview(double) = 0;
    int getMylane() const;

    void setMylane(int mylane);

private:
    coordinats position;
    coordinats size;
    int maxspeed = 20;
    int speed = 0;
    int mylane;

};


#endif //TURBOHIKER_ENTITY_H
