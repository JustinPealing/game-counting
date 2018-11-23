#include <SFML/Graphics.hpp>
#include "GameEngine.hpp"
#include <iostream>

const float window_width = 1280;
const float window_height = 960;

int main()
{
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Counting Game");
    sf::Clock clock;
    window.setFramerateLimit(30);

    GameEngine engine(window);
    engine.Load();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event));
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time dt = clock.restart();
        engine.Update(dt);
        engine.Draw();
    }

    return 0;
}
