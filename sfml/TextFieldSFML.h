//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_TEXTFIELDSFML_H
#define TURBOHIKER_TEXTFIELDSFML_H

#include "../logic/Layout.h"
#include <SFML/Graphics.hpp>

namespace turbohikerSFML {
    class TextFieldSFML : public turbohiker::Layout {
    public:
        TextFieldSFML(sf::RenderWindow &window, sf::Color col, sf::Vector2f position, const std::string &s,
                      const std::shared_ptr<sf::Font> &f, bool t);

        ~TextFieldSFML() override = default;

        void render() override;

        void moveToView(double) override;

        void updateVisuals(turbohiker::Coordinates s) override {};

    private:
        sf::Text body;
        sf::RenderWindow &window;
        std::string text;
//    highscore should not be update but live score should
        bool toupdate = true;
    };
}

#endif //TURBOHIKER_TEXTFIELDSFML_H
