#include "GameEngine.hpp"
#include <sstream>
#include <iostream>
#include <string>
#include <math.h>

const float gravity = 1000;
const float jump_power = 300;
const float scroll_speed = 100;

void GameEngine::Load()
{
    if (!m_tx_unicorn.loadFromFile("data/unicorn.png"))
        throw "Error loading images";
    if (!m_font.loadFromFile("data/ARCADE.TTF"))
        throw "Error loading font";

    m_text.setFont(m_font);
    m_text.setCharacterSize(400);
    m_text.setPosition(sf::Vector2f(1000, 250));
    m_text.setFillColor(sf::Color::Black);

    srand (time(NULL));
    Reset();
}

void GameEngine::Update(sf::Time dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) Input(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) Input(1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) Input(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) Input(3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) Input(4);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) Input(5);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) Input(6);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) Input(7);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) Input(8);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) Input(9);

    sf::Time now = m_clock.getElapsedTime();
    if (m_answercorrect && (now - m_answertime).asSeconds() > 1) {
        Reset();
    }
}

void GameEngine::Input(int number)
{
    if (m_answercorrect) return;
    m_answer = number;
    m_answercorrect = m_answer == m_items.size();
    m_answertime = m_clock.getElapsedTime();
}

void GameEngine::Reset()
{
    m_answer = 0;
    m_answercorrect = false;
    m_items.clear();

    int random = rand() % 9 + 1;
    for (int i = 0; i < random; i++) {
        m_items.push_back(sf::Vector2f(150 + (i % 3) * 250, 150 + (i / 3) * 300));
    }
}

void GameEngine::Draw()
{
    m_window.clear(sf::Color(150, 241, 237));

    sf::Sprite sprite;
    sprite.setTexture(m_tx_unicorn);
    sprite.setOrigin(95, 115);

    float rotation = sin(m_clock.getElapsedTime().asSeconds() * 2) * 4;
    sprite.setRotation(rotation);

    for (std::list<sf::Vector2f>::iterator it = m_items.begin(); it != m_items.end(); it++) {
        sprite.setPosition(*it);
        m_window.draw(sprite, m_rs);
    }

    if (m_answer > 0) {
        std::stringstream ss;
        ss << m_answer;

        m_text.setString(ss.str());
        m_text.setFillColor(m_answercorrect ? sf::Color::Green : sf::Color::Red);
        m_window.draw(m_text);
    }

    m_window.display();
}
