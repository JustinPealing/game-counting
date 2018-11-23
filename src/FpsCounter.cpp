#include "FpsCounter.hpp"
#include <sstream>

void FpsCounter::Update(sf::Time dt)
{
    m_fps = 1.0f / dt.asSeconds();
}

void FpsCounter::SetFont(sf::Font &font)
{
    m_text.setFont(font);
}

void FpsCounter::Draw(sf::RenderWindow &window)
{
    std::ostringstream str;
    str << m_fps << " FPS";
    m_text.setString(str.str());
    window.draw(m_text);
}