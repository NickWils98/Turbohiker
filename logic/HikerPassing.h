//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_HIKERPASSING_H
#define TURBOHIKER_HIKERPASSING_H


#include "Hiker.h"

namespace turbohiker {
    class HikerPassing : public Hiker {
    public:
        std::shared_ptr<Entity> shout(double, double) override;

        Coordinates update() override;

        void removeBuff() override;

        void setKnight(bool h);

        void speedup(int, int) override {};

    private:
//    knight if true else Rat
        bool knight = false;
    };
}

#endif //TURBOHIKER_HIKERPASSING_H
