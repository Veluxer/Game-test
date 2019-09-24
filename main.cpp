#include "Personnage.h"
//#include <SFML/Graphics.hpp>

int init_struct_prin(wind_s *window)
{
    std::string name[3] = {"NEW GAME", "LOAD", "EXIT"};
    window->window.setSize(sf::Vector2u(800, 600));
    window->window.setTitle("XxX");
    if (!window->font.loadFromFile("font/anythingyouwant.ttf")) {
            std::cout << "welp, no signe of the font\n";
    }
    for (int i = 0; i < 3; i++) {
    window->text[i].setFont(window->font);
    window->text[i].setString(name[i]);
    window->text[i].setCharacterSize(42);
    window->text[i].setStyle(sf::Text::Bold);
    window->text[i].setPosition(200,150 + i * 100);
    }
    window->text[0].setColor(sf::Color::Red);
    return 0;
}

int main()
{
    wind_s *window = new wind_s;

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    init_struct_prin(window);
    while (window->window.isOpen())
    {
        window->time = window->clock.getElapsedTime();
        while (window->window.pollEvent(window->event))
        {
            if (window->event.type == sf::Event::Closed)
                window->window.close();
        }
        window->window.clear();
        //window.draw(shape);
        window->draw_menu();
        window->window.display();
    }
    delete window;
    return 0;
}
