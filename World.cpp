//
// Created by nick on 27.12.20.
//

#include <iostream>
#include "World.h"

World::World() {
    entityList = {};
}
void World::remove(std::shared_ptr<Entity> toDel) {

}

void World::render() {
    for(auto obj: entityList)
        obj->render();
}

void World::update() {

}

void World::add(std::shared_ptr<Entity> obj) {
    entityList.push_back(obj);
    std::cout<<entityList.size();
}
