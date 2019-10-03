#include "Personnage.h"

Weapon::Weapon(std::string name, int dam, int poi, int bleed) : m_damage(dam), m_poison(poi), m_bleed(bleed)
{
    m_name = name;
}

wind_t::wind_t() : window(sf::VideoMode(1920, 1080), "My window", sf::Style::Default), text(), game_state(0), textInput(), main_character("Jack", 50, 50, 1, 1, 1)
{
    return;
}

void wind_t::Dialogue_set(std::string sentence)
{
    m_sentence = sentence;
}

void wind_t::Display_text()
{
    for (int i = 0; m_sentence[i] != '\0'; i++) {
        wait_sec();
        beDisplay += m_sentence[i];
        toDisplay.setString(beDisplay);
        window.draw(toDisplay);
        window.display();
    }
}

Character::Character(std::string name, int mana, int life, int str, int wis, int agi) : m_name(name), m_mana(mana), m_str(str), m_wis(wis), m_agi(agi)
{
    return;
}

Character::changeName(std::string name)
{
    m_name = name;
}

Character::changeMana(int mana)
{
    m_mana += mana;
}

Character::changeLife(int life)
{
    m_life += life;
}

Character::changeStr(int str)
{
    m_str += str;
}

Character::changeWis(int wis)
{
    m_wis += wis;
}

Character::changeAgi(int agi)
{
    m_agi += agi;
}

void wind_t::draw_menu()
{
    for (int i = 0; i< 3 && game_state == 0; i++) {
        window.draw(text[i]);
    }
    return;
}
