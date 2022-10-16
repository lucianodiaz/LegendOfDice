#include "Archer.h"

Archer::Archer(Race race) : Character(race)
{
	m_BaseDamage = 5;
	calculeDamage();
}

void Archer::calculeDamage()
{
	m_Damage = m_BaseDamage + 1.1f + m_stats.strength + 2.4f * m_stats.agility + (1 + rand() % 6);
}
