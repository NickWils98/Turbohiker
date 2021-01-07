//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_HIKERENEMY_H
#define TURBOHIKER_HIKERENEMY_H


#include "Hiker.h"
namespace turbohiker {
    class HikerEnemy : public Hiker {
    public:
        void speedup(int, int) override;

        std::shared_ptr<Entity> shout(double, double) override;

        Coordinates update() override;

        void removeBuff() override;

    };
}

#endif //TURBOHIKER_HIKERENEMY_H
