//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_TRANSFORMATION_H
#define TURBOHIKER_TRANSFORMATION_H

#include <iostream>
#include <tuple>
#include <memory>
#include "../Coordinates.h"

class Transformation {
    static std::shared_ptr<Transformation> instance;
    int window_x = 100;
    int window_y = 100;

    // Private constructor so that no objects can be created.
    Transformation() = default;

public:
    static std::shared_ptr<Transformation> getInstance() {
        if (!instance) {
            instance.reset(new Transformation());
        }
//            instance = std::make_shared<Transformation>();
        return instance;
    }

    Coordinates logic_to_pixles(double x, double y) const;

    int logic_to_pixle_y(double y) const;

    double pixle_to_logic_y(double y) const;

    void changeWindow(const int x, const int y) {
        window_x = x;
        window_y = y;
    }
};

#endif //TURBOHIKER_TRANSFORMATION_H
