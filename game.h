#include "Character.h"
#include <vector>

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	int m_enemiesDefeted{};

private:

	Character* m_player;
	std::vector<Character*> m_enemies;

	Race selectRace()const;
	void selectClass();
	void validateSelection(int& s, const int max)const;
	void processEvents();
	void turnFight();
	void createRandomEnemy();
	Race getRandomRace() const;
	bool m_quit{};
};
