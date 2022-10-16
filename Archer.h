#pragma once
#include "Character.h"
class Archer : public Character
{
public:
	Archer(Race race);
protected:
	void calculeDamage()override;
};

