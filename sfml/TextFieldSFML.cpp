//
// Created by nick on 04.01.21.
//

#include "TextFieldSFML.h"

TextFieldSFML::TextFieldSFML(sf::RenderWindow& w, sf::Color col, sf::Vector2f position, const std::string& s, const std::shared_ptr<sf::Font>& f, bool u)
        : window(w){
    text = s;
    body.setFont(*f);
    body.setString(s);
    body.setCharacterSize( 30);
    body.setFillColor(col);
    body.setPosition(position);
    toupdate = u;
}

TextFieldSFML::~TextFieldSFML() = default;


void TextFieldSFML::render() {
    if(toupdate) {
        body.setString(text + getScoring());
    }

    window.draw(body);
}

void TextFieldSFML::movetoview(double moved) {


    std::shared_ptr<Transformation> t = t->getInstance();
    int oldp = t->logic_to_pixle_y(0);
    int newp = t->logic_to_pixle_y(moved);
    float updatep = (float)newp-(float)oldp;

    body.move(0, updatep);

}

std::shared_ptr<Entity> TextFieldSFML::remove_shout(double timer) {
    return nullptr;
}