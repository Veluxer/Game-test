#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <string>
#include <iostream>

void wait_sec();
void event_loop();

class item
{
public:

protected:
    std::string m_name;
};

class Weapon
{
    public:
        Weapon(std::string name, int dam, int poi, int bleed);
    protected:
        std::string m_name;
        int m_damage;
        int m_poison;
        int m_bleed;
};

class Armor
{
    public:
    private:
        int m_def;
};

class Character
{
    public:
    Character(std::string name, int m_mana, int m_life, int m_str, int m_wis, int m_agi);
    changeName(std::string name);
    changeMana(int mana);
    changeLife(int life);
    changeStr(int str);
    changeWis(int wis);
    changeAgi(int agi);

    protected:

    std::string m_name;
    int m_mana;
    int m_life;
    int m_level;
    int m_str; // base damage(phy), base defense(phy) and life
    int m_wis; // base damage(mana), base defence(mana) and mana
    int m_agi; // base crit, base avoid, base precision
    int *m_weak; //elem weak against
    int *m_strong; //elem strong against
    int m_poison;
    int m_poisonLeft;
    int m_bleed;
    int m_bleedLeft;
    Weapon *m_weapon; // the weapon
};


#endif // PERSONNAGE_H_INCLUDED




#ifndef struct_prin
#define struct_prin
#include <SFML/Graphics.hpp>

typedef struct wind_t{
    wind_t();
    void Display_text(std::string sentence);
    std::string beDisplay;
    sf::Text toDisplay;
    Character main_character;
    void draw_menu();
    sf::RenderWindow window;
    sf::Text text[3];
    int game_state; //if you are in menu screen, combat, ...
    std::string playerInput;
    sf::Text textInput;
    sf::Clock clock;
    sf::Time time;
    sf::Event event;
    sf::Font font;
    int text_place;
    int curr_diplayingtxt;
} wind_s;
#endif //struct_prin


#ifndef tilemap_loader //partially from https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array-fr.php
#define tilemap_loader
class TileMap : public sf::Drawable, public sf::Transformable
{
public:

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};
#endif // tilemap_loader

