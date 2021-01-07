//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H


#include <vector>
#include "Entity.h"
#include "../sfml/LanesSFML.h"
#include "../Factory/HikerFactory/HikerFactory.h"
#include <iostream>
#include "Collider.h"
#include "../Factory/LayoutFactory/LayoutFactory.h"
#include <algorithm>



class World : public Entity {
public:
    World();
    ~World() override = default;
    void remove(std::shared_ptr<Entity> toDel);
    void render() override;
    Coordinates update() override;
    void add(std::shared_ptr<Entity> obj);
    void addLane(std::vector<std::shared_ptr<HikerFactory>> f, std::vector<std::shared_ptr<LayoutFactory>>l, int amount);
    bool updateVisuals(Coordinates s)override{};
    double getplayerposy();
    double getplayerspeed();
    double getplayermaxspeed();
    void speedup(int, int);
    int speedupPlayer(int);
    void movetoview(double) override;

    double gethelper(){return player->helpcout();};

    void setTimer(double timer, double t);

    void removeLock();
    double Collision(int);

    void generateObstacle(std::vector<std::shared_ptr<HikerFactory>> f, int);
    void generateObstacle2(std::shared_ptr<HikerFactory> f, int);
    void removeObstacle();
    std::shared_ptr<Entity> shout(double, double, double) override;
    void removeBalloon();

    std::shared_ptr<Entity> remove_shout(double timer) override;

    void fixdebuff(double) override;

    void setTracklength(int tracklength);

    void setVieuw(double vieuw);
    void removeEnd();

    const std::shared_ptr<Hiker> &getPlayer() const;

    int getFinishing() const;

    int getScore1() const;

private:
    int score = 0;
    int finishing = 0;
    std::vector<int> ai(std::shared_ptr<Entity> e);
    //List of all objects of the world
    std::vector<std::shared_ptr<Entity>> entityList;
    int lanes = 0;
    std::vector<std::shared_ptr<Entity>> lanelist;
    std::shared_ptr<Hiker> player = nullptr;
    double lanelength =0;
    double firstlane =0;
    double timer;
    std::vector<std::shared_ptr<Entity>> obstacles = {};
    double tracklength = 86;
    void ObstacleInLane(std::shared_ptr<Entity> e, int);
    bool CheckClosesdObstacleInLane(std::shared_ptr<Entity> e, int);

    std::vector<bool> checklaneswitch(std::shared_ptr<Entity> e);
    double vieuw = 0;


};


#endif //TURBOHIKER_WORLD_H
