//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_PLAYER_H
#define TURBOHIKER_PLAYER_H


#include "Entity.h"

class player : public Entity {
public:
    player()= default;

    virtual ~player() = default;

    virtual void render() = 0;
    virtual void update() = 0;
};


#endif //TURBOHIKER_PLAYER_H
