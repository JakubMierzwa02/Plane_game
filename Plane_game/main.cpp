#include "Game.h"

#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(NULL));

	Game game;
	game.run();

	return 0;
}
