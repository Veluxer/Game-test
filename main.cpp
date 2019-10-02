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
    window->textInput.setFont(window->font);
    window->textInput.setCharacterSize(42);
    window->textInput.setPosition(200, 150);
    window->toDisplay.setFont(window->font);
    window->toDisplay.setCharacterSize(42);
    window->toDisplay.setPosition(50, 350);
    return 0;
}

void wait_sec()
{
    sf::Clock clock;
    sf::Time elapsed = clock.getElapsedTime();
    float sec = 0;
    while (0.1 > sec) {
        sec = elapsed.asSeconds();
        elapsed = clock.getElapsedTime();
    }
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                window->game_state = window->text_place + 1;
                if (window->game_state == 1) {
                    window->Display_text("Please, Enter your Name...");
                }
    }
    }
}

void new_game(wind_s *window)
{
    if (window->game_state == 1) { //1 is name input
                if (window->event.type == sf::Event::TextEntered)
                {
                    window->playerInput += window->event.text.unicode;
                    window->textInput.setString(window->playerInput);
                }
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))) {
                    window->main_character.changeName(window->playerInput);
                    window->game_state = 11;
                }
    }
    return;
}

void event_loop(wind_s *window)
{
    while (window->window.pollEvent(window->event))
        {
            if (window->event.type == sf::Event::Closed || window->game_state == 3)
                window->window.close();
            menu_principal(window);
            new_game(window);
        }
}

int main()
{
    wind_s *window = new wind_s;

    //sf::SquareShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    init_struct_prin(window);
    while (window->window.isOpen())
    {
        window->window.clear();

        window->time = window->clock.getElapsedTime();
        event_loop(window); //where the event are
        if (window->game_state == 1) {
            window->window.draw(window->toDisplay);
            window->window.draw(window->textInput);
        }
        //window.draw(shape);
        if (window->game_state == 0) {
            window->text[window->text_place].setFillColor(sf::Color::Red);
            window->draw_menu();
        }
        window->window.display();
    }
    delete window;
    return 0;
}
