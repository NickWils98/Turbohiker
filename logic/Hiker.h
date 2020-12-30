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
    void updatePlayerv(int);
    void updatePlayerh(int);
    tuple<double, double> update();
    void movetoview(double) override;
    virtual double helpcout(){return 0;};

    int getLanes() const;

    void setLanes(int lanes);

    int getMylane() const;

    void setMylane(int mylane);


private:
    int lanes;
    int mylane;
    int move = 0;
};


#endif //TURBOHIKER_HIKER_H
