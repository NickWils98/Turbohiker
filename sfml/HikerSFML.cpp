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

void HikerSFML::updateVisuals(std::tuple<int, int> pos, double posi) {
    sf::Vector2f sfmlpos = sf::Vector2f();
    //std::cout<<std::get<1>(pos)<<std::endl;
    sf::Vector2f fff = body.getPosition();

    Transformation *t = t->getInstance();
    tuple<int, int> oldp = t->logic_to_pixles(0,0);
    tuple<int, int> newp = t->logic_to_pixles(0, posi);
    tuple<int, int> updatep = make_tuple(std::get<0>(oldp)- std::get<0>(newp), std::get<1>(oldp)- std::get<1>(newp));
    body.setPosition(body.getPosition().x, std::get<1>(newp)-std::get<1>(oldp) +view.getCenter().y);
    body.move(std::get<0>(pos),0);



}


HikerSFML::~HikerSFML() = default;


