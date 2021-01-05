//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H
#include <memory>
#include <tuple>
#include "ColorLogic.h"
#include "../Transformation.h"
#include "../RandomeNumber.h"
#include "../Subject.h"
#include "../Scoring.h"
#include "../Client.h"

class Entity {
public:
    struct coordinats {
        double x = 0;
        double y = 0;
    };
    const coordinats &getPosition() const;
    const coordinats &getSize() const;
    void setPosition(double x, double y);
    void setPosition(const coordinats &position);
    void setSize(double x, double y);
    double getSpeed() const;
    double getMaxSpeed() const;

    void setMaxspeed(double maxspeed);

    void setSpeed(double speed);
    int getMylane() const;
    void setMylane(int mylane);


    virtual double helpcout(){return 0;};

    Entity(){
        subject = std::make_shared<Scoring>();
        std::shared_ptr<Observer> o = std::make_shared<Client>();
        subject->registerObserver(o);
        observer.push_back( o);
    };
    coordinats GetHalfSize();
    void Move(double dx, double dy){setPosition(getPosition().x+dx, getPosition().y+dy);};


    virtual ~Entity() = default;

    virtual void render() = 0;
    virtual std::tuple<double, double> update() = 0;
    virtual bool updateVisuals(std::tuple<int, int> s) = 0;
    virtual void movetoview(double) = 0;
    virtual void speedup(int, int) = 0;
    virtual std::shared_ptr<Entity> shout(double, double, double) = 0;

    double getHeavynes() const;

    void setHeavynes(double heavynes);

    bool isGottrough() const;

    void setGottrough(bool gottrough);

    bool isSlowdown() const;

    void setSlowdown(bool slowdown);

    bool isHasballoon() const;

    void setHasballoon(bool hasballoon);

    const std::shared_ptr<Entity> &getBalloon() const;
    virtual std::shared_ptr<Entity> remove_shout(double timer) =0;


    void setBalloon(const std::shared_ptr<Entity> &balloon);

    bool isDebuff() const;

    void setDebuff(bool debuff);

    virtual void fixdebuff(double) = 0;

    double getDebufftimer() const;

    void setDebufftimer(double debufftimer);

    double getLock() const;

    void setLock(double lock);

    bool isLocked() const;

    void setLocked(bool locked);

    bool isWannashout() const;

    void setWannashout(bool wannashout);

    double getTimer() const;

    void setTimer(double timer);

    bool isIsobstacle() const;

    void setIsobstacle(bool isobstacle);

    double getOldtimer() const;

    void setOldtimer(double oldtimer);

    int getScore() const;

    void setScore(int score);

    const std::string &getScoring() const;

    void setScoring(const int &scoring);

private:
    std::string scoring ="";
    std::shared_ptr<Subject> subject;
    std::vector<std::shared_ptr<Observer>> observer;
    int score = 0;
    coordinats position;
    coordinats size;
    double maxspeed = 120;
    double speedv = 0;
    int speedh = 0;
    double timer = 0;
    double oldtimer = 0;

    double heavynes = 0;
    bool gottrough = false;
    bool slowdown = false;
    bool hasballoon = false;
    bool debuff = false;
    double debufftimer = 0;
    double lock=0;
    bool locked = false;
    std::shared_ptr<Entity> balloon= nullptr;
    bool wannashout = false;
    bool isobstacle = false;
    bool enemy = false;
public:
    bool isEnemy() const;

    void setEnemy(bool enemy);

    int getSpeedh() const;

    void setSpeedh(int speedh);

private:
    int mylane;

};


#endif //TURBOHIKER_ENTITY_H
