//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H


#include "Entity.h"

class World : public Entity {
    World();

    virtual ~World();

    void add(std::shared_ptr<Entity> obj);
    void remove(std::shared_ptr<Entity> toDel);
    void render();
    void update();
};


#endif //TURBOHIKER_WORLD_H
