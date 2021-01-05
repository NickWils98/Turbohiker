//
// Created by nick on 04.01.21.
//

#include "TextFieldSFML.h"

TextFieldSFML::TextFieldSFML(sf::RenderWindow& w, sf::Color col, sf::Vector2f size, sf::Vector2f position, std::string s, const std::shared_ptr<sf::Font>& f)
        : window(w){
//    sf::String se = "Text";
    font = f;
    text = s;
    body.setFont(*f);
    body.setString(s);
    body.setCharacterSize( 30);
////    body.setSize(size);
    body.setFillColor(col);
    body.setPosition(position);
//    text =
//    body.setOrigin(size/2.0f);
}

TextFieldSFML::~TextFieldSFML() {

}


void TextFieldSFML::render() {
    body.setString(text+getScoring());
    window.draw(body);
}

void TextFieldSFML::movetoview(double moved) {


    std::shared_ptr<Transformation> t = t->getInstance();
    std::tuple<int, int> oldp = t->logic_to_pixles(0,0);
    std::tuple<int, int> newp = t->logic_to_pixles(0, moved);
    int tester = std::get<1>(newp)- std::get<1>(oldp);
    body.move(0, tester);

}

std::shared_ptr<Entity> TextFieldSFML::remove_shout(double timer) {
    return std::shared_ptr<Entity>();
}
