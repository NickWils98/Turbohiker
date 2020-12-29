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
        float x = 0;
        float y = 0;
    };
    const coordinats &getPosition() const;
    const coordinats &getSize() const;
    void setPosition(float x, float y);
    void setPosition(const coordinats &position);
    void setSize(float x, float y);
    float getSpeed() const;
    void setSpeed(float speed);

    Entity() = default;

    virtual ~Entity() = default;

    virtual void render() = 0;
    virtual void update() = 0;
    virtual void updateVisuals(std::tuple<int, int> s) = 0;

private:
    coordinats position;
    coordinats size;
    float maxspeed = 50;
    float speed = 0;

};


#endif //TURBOHIKER_ENTITY_H
