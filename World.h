//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H


#include <vector>
#include "Entity.h"

class World {
public:
    World();
    virtual ~World() = default;
    void remove(std::shared_ptr<Entity> toDel);
    void render();
    void update();
    void add(std::shared_ptr<Entity> obj);

private:
    //List of all objects of the world
    std::vector<std::shared_ptr<Entity>> entityList;


};


#endif //TURBOHIKER_WORLD_H
