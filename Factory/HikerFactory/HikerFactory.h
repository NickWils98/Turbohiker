//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_HIKERFACTORY_H
#define TURBOHIKER_HIKERFACTORY_H

#include <memory>
#include <vector>
#include "../../logic/Singletons/Transformation.h"
#include "../../logic/Hiker.h"


class HikerFactory {
public:
    virtual std::shared_ptr<Hiker> createHiker(Coordinates size, Coordinates position) = 0;


};


#endif //TURBOHIKER_HIKERFACTORY_H
