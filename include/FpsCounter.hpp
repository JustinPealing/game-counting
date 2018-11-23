#pragma once

#include <SFML/Graphics.hpp>

class FpsCounter 
{
    sf::Text m_text;
    float m_fps = 0;

public:
    FpsCounter()
    {
        m_text.setCharacterSize(20);
        m_text.setStyle(sf::Text::Bold);
        m_text.setFillColor(sf::Color::White);
        m_text.setPosition(0,0);
    }

    void SetFont(sf::Font &font);
    void Update(sf::Time dt);
    void Draw(sf::RenderWindow &window);
};
