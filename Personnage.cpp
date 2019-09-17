#include "Personnage.h"

Weapon::Weapon(std::string name, int dam, int poi, int bleed) : m_damage(dam), m_poison(poi), m_bleed(bleed)
{
    m_name = name;
}
