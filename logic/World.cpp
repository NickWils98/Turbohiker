//
// Created by nick on 27.12.20.
//

#include "World.h"

World::World() {
    entityList = {};
    lanelist = {};
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

void World::addLane(std::shared_ptr<Factory> f, const int amount) {
    float extra = 8.0/amount;
    float start = -4 + extra;
    for(int count = 0; count<amount;count++){
        ColorLogic c = ColorLogic(255, 255, 255);
        std::shared_ptr<Entity> entity = f->addLane(c, std::tuple<float, float>(-3.9f, 3.0f), std::tuple<float, float>(start, -3.0f));
        entityList.push_back(entity);
        start += extra;
    }


    //player = factory->createHiker(m_window, tex);
}
