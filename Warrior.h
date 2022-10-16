#pragma once
#include "Character.h"
class Warrior : public Character
{
public:
	Warrior(Race race);

protected:
	void calculeDamage() override;
};

