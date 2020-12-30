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
    tuple<double, double> update() override;
    void add(std::shared_ptr<Entity> obj);
    void addLane(std::shared_ptr<Factory> f, int amount);
    void updateVisuals(std::tuple<int, int> s)override{};
    double getplayerposy();
    double getplayerspeed();
    double getplayermaxspeed();
    void speedupPlayer(int, int);
    void movetoview(double) override;

    double gethelper(){return player->helpcout();};

    void setTimer(double timer);

    void removeLock();

private:
    //List of all objects of the world
    std::vector<std::shared_ptr<Entity>> entityList;
    int lanes = 0;
    std::vector<std::shared_ptr<Entity>> lanelist;
    std::shared_ptr<Hiker> player = nullptr;
    double lanelength;
    double timer;
    double lock=0;
    bool locked = false;



};


#endif //TURBOHIKER_WORLD_H
