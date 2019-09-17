#include "Personnage.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::Clock clock;
    sf::Time time;
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        time = clock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (time.asSeconds() > 2 && time.asSeconds() < 3) {
            shape.setFillColor(sf::Color::Red);
        } else if  ((time.asSeconds() > 1) && (time.asSeconds() < 2)) {
            shape.setFillColor(sf::Color::Blue);
        } else if (time.asSeconds() >= 3) {
            clock.restart();
        } else {
            shape.setFillColor(sf::Color::Green);
        }
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
