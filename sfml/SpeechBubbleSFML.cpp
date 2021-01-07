//
// Created by nick on 02.01.21.
//

#include "SpeechBubbleSFML.h"
SpeechBubbleSFML::SpeechBubbleSFML(sf::RenderWindow& w, const std::shared_ptr<sf::Texture>& tex, sf::Vector2f size, sf::Vector2f position, sf::View& v)
        : window(w), view(v)
{
    body.setTexture(tex.get());
    body.setPosition(position);
    body.setSize(size);
    body.setOrigin(size/2.0f);

}



void SpeechBubbleSFML::render() {
    window.draw(body);
}

void SpeechBubbleSFML::updateVisuals(Coordinates pos) {
    std::shared_ptr<Transformation> t = t->getInstance();
    int oldp = t->logic_to_pixle_y(0);
    int newp = t->logic_to_pixle_y(getPosition().y);
    float updatep = (float)newp-(float)oldp;
    body.setPosition(body.getPosition().x, updatep +view.getCenter().y);
    body.move(pos.x,0);
}



