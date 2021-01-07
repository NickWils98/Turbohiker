//
// Created by nick on 30.12.20.
//

#ifndef TURBOHIKER_COLLIDER_H
#define TURBOHIKER_COLLIDER_H


#include <memory>
#include "Hiker.h"
namespace turbohiker {
    class Collider {
    public:
        explicit Collider() = default;

        ~Collider() = default;

        static std::vector<double>
        CollisionDetection(std::shared_ptr<Entity> &first, std::shared_ptr<Entity> &other, double timer);

        static bool checklaneswitch(const std::shared_ptr<Entity> &first, const std::shared_ptr<Entity> &other, bool);

        static bool CheckCollision(const std::shared_ptr<Entity> &first, const std::shared_ptr<Entity> &other);
    };
}

#endif //TURBOHIKER_COLLIDER_H
