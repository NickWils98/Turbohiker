//
// Created by nick on 28.12.20.
//

#include "LanesSFML.h"

LanesSFML::LanesSFML(sf::RenderWindow& w, sf::Color col, sf::Vector2f size, sf::Vector2f position)
        : window(w){

    body.setSize(size);
    body.setFillColor(col);
    body.setPosition(position);
    //body.setOrigin(size/2.0f);
}

LanesSFML::~LanesSFML() {

}


void LanesSFML::render() {
    window.draw(body);
}

void LanesSFML::movetoview(double moved) {


    Transformation *t = t->getInstance();
    tuple<int, int> oldp = t->logic_to_pixles(0,0);
    tuple<int, int> newp = t->logic_to_pixles(0, moved);
    int tester = std::get<1>(newp)- std::get<1>(oldp);
    body.move(0, tester);

}