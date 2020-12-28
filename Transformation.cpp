//
// Created by nick on 28.12.20.
//

#include "Transformation.h"
Transformation* Transformation::instance = 0;
tuple<int, int> Transformation::logic_to_pixles(float x, float y) const {
    x+=4;
    y+=3;
    x /=8;
    y /=6;
    x*=window_x;
    y*= window_y;
    tuple<int, int>toreturn = make_tuple(x,y);
    return toreturn;
}
tuple<float, float> Transformation::pixle_to_logic(float x, float y) {
    x/=window_x;
    y/= window_y;
    x *=8;
    y *=6;
    x-=4;
    y-=3;
    tuple<float, float>toreturn = make_tuple(x,y);
    return toreturn;
}