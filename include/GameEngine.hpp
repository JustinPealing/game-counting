#pragma once

#include <SFML/Graphics.hpp>
#include <list>

class GameEngine 
{
    sf::RenderWindow &m_window;
    sf::Texture m_tx_unicorn;
    sf::Font m_font;
    sf::RenderStates m_rs;

    std::list<sf::Vector2f> m_items
    {
        sf::Vector2f(100, 400),
        sf::Vector2f(200, 200),
        sf::Vector2f(300, 400)
    };

    int m_answer = -1;
    bool m_answercorrect = false;

    sf::Text m_text;

public:
    GameEngine(sf::RenderWindow & window) : m_window(window)
    {
        m_rs.transform.scale(1, 1);
    }

    void Load();
    void Update(sf::Time dt);

    void Input(int number);
    void Reset();

    void Draw();
};
