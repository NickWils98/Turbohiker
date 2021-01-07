//
// Created by nick on 27.12.20.
//

#include "HikerSFML.h"

HikerSFML::HikerSFML(sf::RenderWindow& w, const std::shared_ptr<sf::Texture>& tex, sf::Vector2f size, sf::Vector2f position,sf::View& v)
        : window(w), view(v)
{
    body.setTexture(tex.get());
    body.setPosition(position);
    body.setSize(size);
    body.setOrigin(size/2.0f);

}



void HikerSFML::render() {
    window.draw(body);
}

bool HikerSFML::updateVisuals(Coordinates pos, double posi) {
    std::shared_ptr<Transformation>t = t->getInstance();
    int oldp = t->logic_to_pixle_y(0);
    int newp = t->logic_to_pixle_y(posi);
    float updatep = (float)newp-(float)oldp;
    body.setPosition(body.getPosition().x, updatep +view.getCenter().y);
    body.move(pos.x,0);
    if(body.getPosition().y>window.getSize().y){
        body.setPosition(body.getPosition().x, window.getSize().y);
//        todo: remove this?
        return false;
    }
    return true;



}


HikerSFML::~HikerSFML() = default;


