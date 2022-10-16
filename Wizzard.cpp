#include "Wizzard.h"

Wizzard::Wizzard(Race race): Character(race)
{
	m_BaseDamage = 2;
	calculeDamage();
}

void Wizzard::calculeDamage()
{
	m_Damage = m_BaseDamage+1.1f*m_stats.agility+2.4f*m_stats.intelligence + (1 + rand() % 6);
}
