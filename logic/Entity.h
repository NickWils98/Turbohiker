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
    int getSpeed() const;
    int getMaxSpeed() const;
    void setSpeed(int speed);
    int getMylane() const;
    void setMylane(int mylane);


    virtual double helpcout(){return 0;};

    Entity() = default;
    coordinats GetHalfSize();
    void Move(double dx, double dy){setPosition(getPosition().x+dx, getPosition().y+dy);};


    virtual ~Entity() = default;

    virtual void render() = 0;
    virtual tuple<double, double> update() = 0;
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

    const shared_ptr<Entity> &getBalloon() const;
    virtual std::shared_ptr<Entity> remove_shout(double timer) =0;


    void setBalloon(const shared_ptr<Entity> &balloon);

private:
    coordinats position;
    coordinats size;
    int maxspeed = 120;
    int speedv = 0;
    int speedh = 0;

    double heavynes = 0;
    bool gottrough = false;
    bool slowdown = false;
    bool hasballoon = false;
    std::shared_ptr<Entity> balloon= nullptr;
public:
    int getSpeedh() const;

    void setSpeedh(int speedh);

private:
    int mylane;

};


#endif //TURBOHIKER_ENTITY_H
