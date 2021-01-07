//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H


#include "Entity.h"
#include "../Factory/HikerFactory/HikerFactory.h"
#include "../Factory/LayoutFactory/LayoutFactory.h"
#include "Collider.h"


class World : public Entity {
public:
    World() = default;

    ~World() override;

    void
    initGame(std::vector<std::shared_ptr<HikerFactory>> hikerFactorys,
             std::vector<std::shared_ptr<LayoutFactory>> layoutFactorys, int amount);

    void generateObstacle(std::vector<std::shared_ptr<HikerFactory>> f, int);

    void removeEntity();

    void removeTimeLock();

    void render() override;

    Coordinates update() override;

    std::shared_ptr<Entity> shout(double, double) override;

    void speedup(int speedv, int speedh) override;

    void moveToView(double moved) override;

    double Collision();

    void setTimers(double timer, double delta);

    void removeBuff() override;

    double getPlayerPosy();

    double getPlayerSpeed();

    double getPlayerMaxSpeed();

    bool isPlayerBuffed();

    void setTracklength(int tracklength);

    void setViewPos(double view);

    bool isFinished() const;

    int getPlacement() const;

    int getWorldScore() const;

private:
    void addLaneLine(const std::shared_ptr<LayoutFactory> &factory, double firstlanePos);

    void addPlayer(const std::shared_ptr<HikerFactory> &factory, int place);

    void addEnemy(const std::shared_ptr<HikerFactory> &factory, int place);

    void addLayout(std::vector<std::shared_ptr<LayoutFactory>> factorys);

    void remove(std::shared_ptr<Entity> &toDel);

    void removeHelper(std::shared_ptr<Entity> &toDel);

    std::shared_ptr<Entity> removeShout(bool force) override { return nullptr; };

    void updateVisuals(Coordinates s) override {};

    int speedupPlayer(int speedh);

    std::vector<int> ai(const std::shared_ptr<Entity> &entity);

    void obstacleInLane(const std::shared_ptr<Entity> &e, int distance);

    bool checkClosesdObstacleInLane(const std::shared_ptr<Entity> &hiker, int distance);

    std::vector<bool> checkLaneSwitch(const std::shared_ptr<Entity> &e);

private:
    //List of all hikers of the world
    std::vector<std::shared_ptr<Entity>> entityList = {};
    //List of all obstacles of the world
    std::vector<std::shared_ptr<Entity>> obstacles = {};

    std::shared_ptr<Hiker> player = nullptr;
    int worldScore = 0;
    int placement = 0;
    int playercount = 0;
    double laneWidth = 0;
    double tracklength = 86;
    double firstPlayerPos = 0;
    double viewPos = 0;
};


#endif //TURBOHIKER_WORLD_H
