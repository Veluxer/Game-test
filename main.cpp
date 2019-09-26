#include "Personnage.h"
//#include <SFML/Graphics.hpp>

int init_struct_prin(wind_s *window)
{
    std::string name[3] = {"NEW GAME", "LOAD", "EXIT"};
    window->text_place = 0;
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
    window->text[0].setFillColor(sf::Color::Red);
    return 0;
}

void menu_principal(wind_s *window)
{
    if (window->game_state == 0) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    if (window->text_place != 2) {
                        window->text[window->text_place].setFillColor(sf::Color::White);
                        window->text_place +=1;
                    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    if (window->text_place != 0) {
                        window->text[window->text_place].setFillColor(sf::Color::White);
                        window->text_place -=1;
                    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                window->game_state = window->text_place;
    }
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
            if (window->event.type == sf::Event::Closed || window->game_state == 2)
                window->window.close();
            menu_principal(window);
        }
        window->text[window->text_place].setFillColor(sf::Color::Red);
        window->window.clear();
        //window.draw(shape);
        window->draw_menu();
        window->window.display();
    }
    delete window;
    return 0;
}
