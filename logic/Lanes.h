//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_LANES_H
#define TURBOHIKER_LANES_H


#include "Entity.h"
namespace turbohiker {
    class Lanes : public Entity {
    public:
        void render() override {};

        Coordinates update() override { return {0, 0}; };

        void updateVisuals(Coordinates s) override {};

        void speedup(int, int) override {};

        void removeBuff() override {};

        std::shared_ptr<Entity> removeShout(bool force) override { return nullptr; };

        std::shared_ptr<Entity> shout(double e, double g) override { return nullptr; };
    };
}

#endif //TURBOHIKER_LANES_H
