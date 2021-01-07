//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_HIKERFACTORY_H
#define TURBOHIKER_HIKERFACTORY_H

#include <memory>
#include <vector>
#include "../Singletons/Transformation.h"
#include "../Hiker.h"

namespace turbohiker {
    class HikerFactory {
    public:
        virtual std::shared_ptr<Hiker> createHiker(Coordinates size, Coordinates position) = 0;


    };
}

#endif //TURBOHIKER_HIKERFACTORY_H
