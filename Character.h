#pragma once

#include <iostream>
#include <string>
#include "Race.h"
#include "Stats.h"


using std::cout;
using std::endl;

class Character
{
public: 
	Character() = delete;

	Character(Race race);

	void draw();
	virtual ~Character();


	float getHealth()const;
	float getMana()const;
	float getLastDamage()const;

	std::string getRaceName();


	void applyDamage(Character& otherCharacter);
	void takeDamage(float dmg);

	void heal(float health);
protected: 

	void initiliazeStats();

	virtual void calculeDamage();

	
protected:

	float m_Health{};
	float m_Mana{};
	float m_Damage{};

	float m_BaseDamage{};

	const int BASE_HEALTH = 50;
	const int BASE_MANA = 20;

	Stats m_stats;
	Race m_race;

};

