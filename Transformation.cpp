//
// Created by nick on 28.12.20.
//

#include "Transformation.h"
Transformation* Transformation::instance = 0;
tuple<int, int> Transformation::logic_to_pixles(double x, double y) const {
    x+=4;
    y+=3;
    x /=8.0;
    y /=6.0;
    x*=window_x;
    y*= window_y;
    if(y>0){
        y+=0.5;
    }
    if(y<0){
        y-=0.5;
    }
    tuple<int, int>toreturn = make_tuple(x+0.5,y);
    return toreturn;
}
tuple<double, double> Transformation::pixle_to_logic(double x, double y) {
    x/=window_x;
    y/= window_y;
    x *=8;
    y *=6;
    x-=4;
    y-=3;
    tuple<double, double>toreturn = make_tuple(x,y);
    return toreturn;
}

int Transformation::logic_to_pixle_y(double y) const {
    y+=3;
    y /=6.0;
    y*= window_y;
    if(y>0){
        y+=0.5;
    }
    if(y<0){
        y-=0.5;
    }
    return y;
}

double Transformation::pixle_to_logic_y(double y) const {
    y/= window_y;
    y *=6;
    y-=3;
    return y;
}
