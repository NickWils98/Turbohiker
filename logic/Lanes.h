//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_LANES_H
#define TURBOHIKER_LANES_H


#include "Entity.h"

class Lanes : public Entity{
public:
    void render() override{};
    void update() override{};
    void updateVisuals(std::tuple<int, int> s)override{};
};


#endif //TURBOHIKER_LANES_H
