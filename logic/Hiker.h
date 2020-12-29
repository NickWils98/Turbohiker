//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_HIKER_H
#define TURBOHIKER_HIKER_H


#include "Entity.h"

class Hiker : public Entity {
public:
    Hiker()= default;

    virtual ~Hiker() = default;

    virtual void render() = 0;
    virtual void updateVisuals(std::tuple<int, int> s) = 0;
    void updatePlayer(int speedup);
    void update();
};


#endif //TURBOHIKER_HIKER_H
