//
// Created by nick on 02.01.21.
//

#ifndef TURBOHIKER_BALLOON_H
#define TURBOHIKER_BALLOON_H


#include "Entity.h"

class Balloon : public Entity{
public:

    ~Balloon() override = default;

    virtual void render() = 0;

    Coordinates update() override;

    virtual bool updateVisuals(Coordinates s) = 0;

    void movetoview(double d) override;

    void speedup(int i, int i1) override;

    std::shared_ptr<Entity> shout(double d, double x, double e) override{return nullptr;};

    std::shared_ptr<Entity> remove_shout(double timer) override;

    void fixdebuff(double d) override;
};


#endif //TURBOHIKER_BALLOON_H
