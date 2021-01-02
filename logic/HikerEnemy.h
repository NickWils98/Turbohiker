//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_HIKERENEMY_H
#define TURBOHIKER_HIKERENEMY_H


#include "Hiker.h"

class HikerEnemy : public Hiker {
public:
    HikerEnemy();

    void speedup(int, int) override;
};


#endif //TURBOHIKER_HIKERENEMY_H
