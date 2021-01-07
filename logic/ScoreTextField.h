//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_SCORETEXTFIELD_H
#define TURBOHIKER_SCORETEXTFIELD_H

#include "Entity.h"

namespace turbohiker {
    class ScoreTextField : public Entity {
    public:
        void render() override {};

        void updateVisuals(Coordinates s) override {};

        void speedup(int, int) override {};

        void removeBuff() override {};

        Coordinates update() override { return {0, 0}; };

        std::shared_ptr<Entity> removeShout(bool force) override { return nullptr; };

        std::shared_ptr<Entity> shout(double e, double g) override { return nullptr; }
    };
}

#endif //TURBOHIKER_SCORETEXTFIELD_H
