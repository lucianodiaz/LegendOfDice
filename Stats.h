#pragma once
#include <iostream>
struct Stats
{
	int strength;
	int agility;
	int intelligence;
	void init(int str, int agi, int intel);
	void print() const;
};

inline void Stats::init(int str, int agi, int intel)
{
	strength = str;
	agility = agi;
	intelligence = intel;
}

inline void Stats::print() const
{
	std::cout << "	STR:" << strength << std::endl;
	std::cout << "	AGI:" << agility << std::endl;
	std::cout << "	INT:" << intelligence << std::endl;
}
