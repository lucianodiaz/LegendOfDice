#include "game.h"

int main()
{
	srand(time(NULL));

	Game* game = new Game();

	game->run();

	delete game;
	return 0;
}