//
// Created by nick on 02.01.21.
//

#ifndef TURBOHIKER_LAYOUTFACTORY_H
#define TURBOHIKER_LAYOUTFACTORY_H

#include <memory>
#include <vector>
#include "../Entity.h"
#include "../Singletons/Transformation.h"
namespace turbohiker {
    class LayoutFactory {
    public:
        virtual std::shared_ptr<Entity> createProp(Coordinates size, Coordinates position) = 0;

    };
}

#endif //TURBOHIKER_LAYOUTFACTORY_H
