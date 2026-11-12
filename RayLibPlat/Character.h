#pragma once
#include <iostream>
#include "raylib.h"
#include "Tile.h"
class Character
{
private:

protected:
	Vector2 position;
	Vector2 velocity = { 0, 0 };
	float gravity = .81f;
	const float moveSpeed = 5.0f;
	const float jumpForce = -2;
	float size;
	bool isGrounded = false;
	bool isOnStairs = false;

public:
	Character(Vector2 pos, float s);
	~Character();

	void Update();
	void Draw();
	void Collision(Tile & t);


};

