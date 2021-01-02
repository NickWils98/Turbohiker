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
#include "Collider.h"
#include <algorithm>



class World : public Entity {
public:
    World();
    virtual ~World() = default;
    void remove(std::shared_ptr<Entity> toDel);
    void render();
    tuple<double, double> update() override;
    void add(std::shared_ptr<Entity> obj);
    void addLane(std::shared_ptr<Factory> f, int amount);
    bool updateVisuals(std::tuple<int, int> s)override{};
    double getplayerposy();
    double getplayerspeed();
    double getplayermaxspeed();
    void speedup(int, int);
    int speedupPlayer(int);
    void movetoview(double) override;

    double gethelper(){return player->helpcout();};

    void setTimer(double timer);

    void removeLock();
    double Collision(int);

    void generateObstacle(std::shared_ptr<Factory> f, int);
    void generateObstacle2(std::shared_ptr<Factory> f, int);
    void removeObstacle();


private:
    //List of all objects of the world
    std::vector<std::shared_ptr<Entity>> entityList;
    int lanes = 0;
    std::vector<std::shared_ptr<Entity>> lanelist;
    std::shared_ptr<Hiker> player = nullptr;
    double lanelength =0;
    double firstlane =0;
    double timer;
    double lock=0;
    bool locked = false;
    std::vector<std::shared_ptr<Entity>> obstacles = {};
    int tracklength = 2666;



};


#endif //TURBOHIKER_WORLD_H
