#pragma once
#include "Character.h"
class Wizzard : public Character
{
public:
	Wizzard(Race race);

protected:

	void calculeDamage() override;
};

