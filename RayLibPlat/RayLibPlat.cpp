#include <iostream>
#include "Game.h"
#include <vector>
#include "Tile.h"

int main()
{
	Game game;
	game.InitGame();


	while (!game.IsPlaying())
	{
		game.Update();
		game.Draw();
	}
	CloseWindow();
}
