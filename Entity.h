//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H
#include <memory>


class Entity {
public:
    Entity() = default;

    virtual ~Entity() = default;

    virtual void render() = 0;
    virtual void update() = 0;
};


#endif //TURBOHIKER_ENTITY_H
