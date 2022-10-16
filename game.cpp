#include <conio.h>
#include "Archer.h"
#include "Game.h"
#include "Warrior.h"
#include <Windows.h>
#include "Wizzard.h"

Game::Game()
{
	selectClass();

	for (int i = 0; i < 5; i++)
	{
		createRandomEnemy();
	}
}

Game::~Game()
{
	delete m_player;
}

void Game::selectClass()
{
	int selection{};
	cout << "Select your class: " << endl;
	cout << " 0 - Warrior" << endl;
	cout << " 1 - Wizzard" << endl;
	cout << " 2 - Archer" << endl;
	std::cin >> selection;
	validateSelection(selection, 2);
	switch (selection)
	{
	case 0:
		m_player = new Warrior(selectRace());
		break;
	case 1:
		m_player = new Wizzard(selectRace());
		break;
	case 2:
		m_player = new Archer(selectRace());
		break;
	default:
		break;
	}
}

void Game::run()
{
	m_player->draw();

	processEvents();
}

Race Game::selectRace() const
{
	int selection{};
	cout << "Select your race: " << endl;
	cout << " 0 - HUMAN" << endl;
	cout << " 1 - ELF" << endl;
	cout << " 2 - DWARF" << endl;
	cout << " 3 - ORC" << endl;
	std::cin >> selection;
	validateSelection(selection,((int)Race::COUNT-1));
	return Race(selection);
}


void Game::validateSelection(int& s,const int _max) const
{
	if(!std::cin.fail())
	{
		if (s < 0 || s>_max)
		{
			cout << "You selected a incorrect option by default set 0" << endl;
			s = 0;
		}
	}
	else
	{
		cout << "You selected a incorrect option by defaultset 0" << endl;
		s = 0;
	}
}

void Game::processEvents()
{
	turnFight();

	if (m_player->getHealth() > 0)
	{
		cout << "PLAYER WIN!" << endl;
		cout << "Enemies defeted: "<<m_enemiesDefeted<< endl;
	}
	else
	{
		cout << "PLAYER LOOSE!" << endl;
		cout << "Enemies defeted: " << m_enemiesDefeted << endl;
	}
}

void Game::turnFight()
{
	for (auto&& e : m_enemies)
	{
		if (m_player->getHealth() > 0)
		{
		cout << "Enemies appears!" << endl;
		e->draw();
		bool nextBattle = false;
		
			while (e->getHealth() > 0 || !nextBattle)
			{
				cout << "===========================================" << endl;
				cout << "Player life: " << m_player->getHealth() << endl;
				cout << "Enemy life: " << e->getHealth() << endl;

				m_player->applyDamage(*e);
				cout << "Player cause " << m_player->getLastDamage() << " damage to enemy" << endl;
				cout << "Enemy life: " << e->getHealth() << endl;
				if (e->getHealth() > 0)
				{
					e->applyDamage(*m_player);
					cout << "Enemy cause " << e->getLastDamage() << " damage to player" << endl;
					cout << "Player life: " << m_player->getHealth() << endl;
					cout << "===========================================" << endl;
					if (m_player->getHealth() <= 0)break;
				}
				else
				{
					cout << "Enemy defeated!" << endl;
					cout << " Player Heal" << endl;
					m_player->heal(40);
					nextBattle = true;
					m_enemiesDefeted++;
					cout << "===========================================" << endl;
				}
				//this is to wait a player input
				_getch();
			}
		}
		
	}
}

void Game::createRandomEnemy()
{
	const int random = rand() % 3;
	Character* enemy;
	switch (random)
	{
	case 0:
		enemy = new Warrior(getRandomRace());
		break;
	case 1:
		enemy = new Wizzard(getRandomRace());
		break;
	case 2:
		enemy = new Archer(getRandomRace());
		break;
	default:
		enemy = new Warrior(getRandomRace());
		break;
	}
	m_enemies.emplace_back(enemy);
}

Race Game::getRandomRace() const
{
	return Race(rand() % int(Race::COUNT));
}