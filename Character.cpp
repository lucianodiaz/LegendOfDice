#include "Character.h"

Character::Character(Race race)
{
	m_race = race;
	initiliazeStats();
	m_Health = BASE_HEALTH + 2 * m_stats.strength;
	m_Mana = BASE_MANA + 3 * m_stats.intelligence;
}

void Character::draw()
{
	cout << "----------------" << endl;
	cout << "Health: " << m_Health << endl;
	cout << "Mana: " << m_Mana << endl;
	cout << "Stats: " << endl;
	m_stats.print();
	cout << getRaceName() << endl;
	cout << "----------------" << endl;
}

Character::~Character()
{

}

void Character::initiliazeStats()
{
	switch (m_race)
	{
	case Race::HUMAN:
		m_stats.init(4,3,3);
		break;
	case Race::ELF:
		m_stats.init(2, 4, 4);
		break;
	case Race::DWARF:
		m_stats.init(5, 2, 3);
		break;
	case Race::ORC:
		m_stats.init(6, 2, 2);
		break;
	default:
		break;
	}
}

void Character::calculeDamage()
{
	std::cout << "Calculate Damage each class"<<std::endl;
}

void Character::applyDamage(Character& otherCharacter)
{
	calculeDamage();
	otherCharacter.takeDamage(m_Damage); 
}

void Character::takeDamage(float dmg)
{
	m_Health -= dmg;
}

void Character::heal(float health)
{
	m_Health += health;
}

std::string Character::getRaceName()
{
	switch (m_race)
	{
	case Race::HUMAN:
		return "RACE: HUMAN";
		break;
	case Race::ELF:
		return "RACE: ELF";
		break;
	case Race::DWARF:
		return "RACE: DWARF";
		break;
	case Race::ORC:
		return "RACE: ORC";
		break;
	default:
		return "UCKNOW RACE";
		break;
	}
}

float Character::getHealth() const
{
	return m_Health;
}

float Character::getMana() const
{
	return m_Mana;
}

float Character::getLastDamage() const
{
	return m_Damage;
}
