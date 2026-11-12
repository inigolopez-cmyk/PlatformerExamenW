#pragma once
#include <raylib.h>
#include <vector>
#include "Tile.h"
#include "Brick.h"
#include "Wall.h"
#include "Stair.h"
#include "Character.h"
#include "Player.h"
class Game
{
private:
	bool playing = false;
	const int screenWidth = 800;
	const int screenHeight = 600;
	Vector2 playerPos;
	Player* player;
	std::vector<Tile*> map;
public:
	Game();
	~Game();

	void InitGame();
	void Update();
	void Draw();
	bool IsPlaying() { return WindowShouldClose(); }

};

