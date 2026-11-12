#include "Player.h"

Player::Player(Vector2 pos, float s):
	Character(pos, s)
{

}

Player::~Player()
{

}

void Player::Update()
{
	

	//En player
	if (isGrounded == false) 
	{
		if (IsKeyDown(KEY_UP)) velocity.y -= moveSpeed;
		if (IsKeyDown(KEY_W)) velocity.y -= moveSpeed;
		velocity.y += gravity;
	}
	else
	{
		isGrounded == true;
	}

	//if (IsKeyDown(KEY_DOWN)) velocity.y += moveSpeed;
	//if (IsKeyDown(KEY_S)) velocity.y += moveSpeed;

	if (IsKeyDown(KEY_LEFT)) velocity.x -= moveSpeed;
	if (IsKeyDown(KEY_A)) velocity.x -= moveSpeed;


	if (IsKeyDown(KEY_RIGHT)) velocity.x += moveSpeed;
	if (IsKeyDown(KEY_D)) velocity.x += moveSpeed;

	position.y += velocity.y;
	position.x += velocity.x;
}
