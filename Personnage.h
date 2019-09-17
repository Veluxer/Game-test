#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <string>
#include <iostream>

class Weapon
{
    public:
        Weapon(std::string name, int dam, int poi, int bleed);
    private:
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

    private:

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
