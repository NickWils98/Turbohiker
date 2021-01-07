//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_TEXTFIELD_H
#define TURBOHIKER_TEXTFIELD_H

#include "Entity.h"

class Textfield : public Entity{
public:
    void render() override{};
    Coordinates update() override{return {0, 0};};
    void updateVisuals(Coordinates s)override{};
    virtual void moveToView(double) = 0;
    void speedup(int, int) override{};
    void removeBuff() override{};
    std::shared_ptr<Entity> removeShout(bool force) override{return nullptr;};


    std::shared_ptr<Entity> shout(double e, double g) override {
        return nullptr;
    }
};



#endif //TURBOHIKER_TEXTFIELD_H
