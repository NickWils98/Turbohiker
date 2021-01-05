//
// Created by nick on 02.01.21.
//

#include "BalloonSFML.h"
BalloonSFML::BalloonSFML(sf::RenderWindow& w, const std::shared_ptr<sf::Texture>& tex, sf::Vector2f size, sf::Vector2f position,sf::View& v)
        : window(w), view(v)
{
    body.setTexture(tex.get());
    body.setPosition(position);
    body.setSize(size);
    body.setOrigin(size/2.0f);

}



void BalloonSFML::render() {
    window.draw(body);
}

bool BalloonSFML::updateVisuals(std::tuple<int, int> pos) {
    sf::Vector2f sfmlpos = sf::Vector2f();
    //std::cout<<std::get<1>(pos)<<std::endl;
    sf::Vector2f fff = body.getPosition();

    std::shared_ptr<Transformation> t = t->getInstance();
    std::tuple<int, int> oldp = t->logic_to_pixles(0,0);
    std::tuple<int, int> newp = t->logic_to_pixles(0, getPosition().y);
    std::tuple<int, int> updatep = std::make_tuple(std::get<0>(oldp)- std::get<0>(newp), std::get<1>(oldp)- std::get<1>(newp));
    body.setPosition(body.getPosition().x, std::get<1>(newp)-std::get<1>(oldp) +view.getCenter().y);
    body.move(std::get<0>(pos),0);
    if(body.getPosition().y>window.getSize().y){
        body.setPosition(body.getPosition().x, window.getSize().y);
        return false;
    }
    return true;



}


