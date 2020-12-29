//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H


#include <vector>
#include "Entity.h"
#include "../sfml/LanesSFML.h"
#include "../Factory/Factory.h"
#include <iostream>


class World : public Entity {
public:
    World();
    virtual ~World() = default;
    void remove(std::shared_ptr<Entity> toDel);
    void render();
    void update() override;
    void add(std::shared_ptr<Entity> obj);
    void addLane(std::shared_ptr<Factory> f, int amount);
    void updateVisuals(std::tuple<int, int> s)override{};
    void addHiker(std::shared_ptr<Factory> f, int amount);
    void speedupPlayer(int);

private:
    //List of all objects of the world
    std::vector<std::shared_ptr<Entity>> entityList;
    int lanes = 0;
    std::vector<std::shared_ptr<Entity>> lanelist;
    std::shared_ptr<Hiker> player = nullptr;



};


#endif //TURBOHIKER_WORLD_H
