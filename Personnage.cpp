#include "Personnage.h"

Weapon::Weapon(std::string name, int dam, int poi, int bleed) : m_damage(dam), m_poison(poi), m_bleed(bleed)
{
    m_name = name;
}

wind_t::wind_t() : window(sf::VideoMode(800, 600), "My window", sf::Style::Default), text(), game_state(0)
{
    return;
}

void wind_t::draw_menu()
{
    for (int i = 0; i< 3; i++) {
        window.draw(text[i]);
    }
    return;
}
