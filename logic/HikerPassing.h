//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_HIKERPASSING_H
#define TURBOHIKER_HIKERPASSING_H


#include "Hiker.h"

class HikerPassing : public Hiker {
public:
    HikerPassing();

    void speedup(int, int) override;
    std::shared_ptr<Entity> shout(double, double) override;
    Coordinates update();

    void removeBuff() override;

    bool isHorizontal() const;

    void setHorizontal(bool horizontal);

private:
    int move = 0;
    bool horizontal = false;
};


#endif //TURBOHIKER_HIKERPASSING_H
