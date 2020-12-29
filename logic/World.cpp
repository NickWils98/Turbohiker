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
    for(auto obj: entityList) {
        obj->render();
    }
}

void World::update() {
    for(auto obj: entityList) {
        obj->update();
        coordinats pos = obj->getPosition();
        Transformation *t = t->getInstance();
        tuple<int, int> p = t->logic_to_pixles(pos.x, pos.y);
        obj->updateVisuals(p);
    }

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
        std::shared_ptr<Hiker> hiker = f->createHiker(std::tuple<float, float>(extra-4, -2.5f), std::tuple<float, float>(start-extra/2, 2.6f));
        hiker->setPosition(start-extra/2, 2.6f);

        entityList.push_back(entity);
        entityList.push_back(hiker);
        if(!player){
            player = hiker;
        }
        start += extra;
    }


    //Hiker = factory->createHiker(m_window, tex);
}

void World::speedupPlayer(int speedup) {
    player->updatePlayer(speedup);
}

