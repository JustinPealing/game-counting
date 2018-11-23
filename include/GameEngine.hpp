#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include "FpsCounter.hpp"

class GameEngine 
{
    sf::RenderWindow &m_window;
    sf::Texture m_tx_unicorn;
    sf::Font m_font;
    sf::RenderStates m_rs;
    sf::Text m_text;
    sf::Clock m_clock;
    FpsCounter m_fps;

    std::list<sf::Vector2f> m_items;

    int m_answer = -1;
    bool m_answercorrect = false;
    sf::Time m_answertime;

public:
    GameEngine(sf::RenderWindow & window)
        : m_window(window), m_fps()
    {
        m_rs.transform.scale(1, 1);
    }

    void Load();
    void Update(sf::Time dt);

    void Input(int number);
    void Reset();

    void Draw();
};
