//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_HIKERPLAYER_H
#define TURBOHIKER_HIKERPLAYER_H


#include "Hiker.h"

class HikerPlayer : public Hiker {
public:
    HikerPlayer();

    void speedup(int, int) override;
};


#endif //TURBOHIKER_HIKERPLAYER_H
