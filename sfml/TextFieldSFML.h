//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_TEXTFIELDSFML_H
#define TURBOHIKER_TEXTFIELDSFML_H

#include "../logic/Textfield.h"
#include <SFML/Graphics.hpp>

class TextFieldSFML : public Textfield {
public:
    TextFieldSFML(sf::RenderWindow& window, sf::Color col, sf::Vector2f position, const std::string& s, const std::shared_ptr<sf::Font>& f, bool);
    ~TextFieldSFML() override;

    void render() override;
    void moveToView(double) override;

private:
    sf::Text body;
    sf::RenderWindow& window;
    std::string text;
    bool toupdate = true;
};



#endif //TURBOHIKER_TEXTFIELDSFML_H
