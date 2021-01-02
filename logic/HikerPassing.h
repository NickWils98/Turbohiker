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
};


#endif //TURBOHIKER_HIKERPASSING_H
