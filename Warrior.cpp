#include "Warrior.h"

Warrior::Warrior(Race race) : Character(race)
{
	m_BaseDamage = 5;
	calculeDamage();
}

void Warrior::calculeDamage()
{
	m_Damage = m_BaseDamage + 1.5f * m_stats.strength + 1.2f * m_stats.agility + (1 + rand() % 6);
}
