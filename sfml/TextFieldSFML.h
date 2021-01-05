//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_TEXTFIELDSFML_H
#define TURBOHIKER_TEXTFIELDSFML_H

#include "../logic/Textfield.h"
#include <SFML/Graphics.hpp>

class TextFieldSFML : public Textfield {
public:
    TextFieldSFML(sf::RenderWindow& window, sf::Color col, sf::Vector2f size, sf::Vector2f position, std::string s, const std::shared_ptr<sf::Font>& f, bool);
    ~TextFieldSFML();

    void render();
    void movetoview(double) override;

    std::shared_ptr<Entity> remove_shout(double timer) override;

    bool isToupdate() const;

    void setToupdate(bool toupdate);

private:
    sf::Text body;
    sf::RenderWindow& window;
    std::string text;
    std::shared_ptr<sf::Font> font;
    bool toupdate = true;
};



#endif //TURBOHIKER_TEXTFIELDSFML_H
