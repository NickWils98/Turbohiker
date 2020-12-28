//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_COLORLOGIC_H
#define TURBOHIKER_COLORLOGIC_H


#include <vector>

class ColorLogic {
private:
    int blue;
    int green;
    int red;
public:
    ColorLogic(int b, int g,int r): blue(b), green(g), red(r){};
    std::vector<int> getColors(){return {red, green, blue};};
    void setColors(int r, int g,int b){blue=b; red = r; green = g;}
};


#endif //TURBOHIKER_COLORLOGIC_H
