//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_TEXTFIELD_H
#define TURBOHIKER_TEXTFIELD_H

#include "Entity.h"

class Textfield : public Entity{
public:
    void render() override{};
    std::tuple<double, double> update() override{return std::make_tuple(0,0);};
    bool updateVisuals(std::tuple<int, int> s)override{};
    virtual void movetoview(double) = 0;
    void speedup(int, int) override{};
    void fixdebuff(double) override{};

    std::shared_ptr<Entity> shout(double d, double e, double g) override {
        return nullptr;
    }
};



#endif //TURBOHIKER_TEXTFIELD_H
