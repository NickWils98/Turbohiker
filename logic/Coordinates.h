//
// Created by nick on 06.01.21.
//

#ifndef TURBOHIKER_COORDINATES_H
#define TURBOHIKER_COORDINATES_H

namespace turbohiker {
    class Coordinates {
    public:
        Coordinates(double x1, double y1) {
            x = x1;
            y = y1;
        };
        double x = 0;
        double y = 0;
    };
}

#endif //TURBOHIKER_COORDINATES_H
