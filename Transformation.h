//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_TRANSFORMATION_H
#define TURBOHIKER_TRANSFORMATION_H

#include <iostream>
#include <tuple>
using namespace std;
class Transformation {
    static Transformation *instance;
    int window_x = 100;
    int window_y=100;
    // Private constructor so that no objects can be created.
    Transformation()=default;

public:
    static Transformation *getInstance() {
        if (!instance)
            instance = new Transformation();
        return instance;
    }

    tuple<int, int> logic_to_pixles(float x, float y) const;

    tuple<float, float> pixle_to_logic(float x, float y);
    void changeWindow(const int x, const int y){
        window_x = x;
        window_y = y;
    }
};

#endif //TURBOHIKER_TRANSFORMATION_H
