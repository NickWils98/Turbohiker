//
// Created by nick on 02.01.21.
//

#ifndef TURBOHIKER_BALLOON_H
#define TURBOHIKER_BALLOON_H


#include "Entity.h"
namespace turbohiker {
    class Balloon : public Entity {
    public:
        ~Balloon() override = default;

        Coordinates update() override { return {0, 0}; };

        void moveToView(double d) override {};

        void speedup(int i, int i1) override {};

        std::shared_ptr<Entity> shout(double x, double e) override { return nullptr; };

        std::shared_ptr<Entity> removeShout(bool force) override { return nullptr; };

        void removeBuff() override {};
    };
}

#endif //TURBOHIKER_BALLOON_H
