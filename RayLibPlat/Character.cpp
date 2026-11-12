#include "Character.h"

Character::Character(Vector2 pos, float s): 
	position(pos),size(s) // = this-> pos; this size;
{
}

Character::~Character()
{
}

void Character::Update()
{
	velocity.y += gravity;


	position.y += velocity.y;
	position.x += velocity.x;
}

void Character::Draw()
{
	DrawRectangle(position.x, position.y, size, size, BLUE);
}

void Character::Collision(Tile& t)
{
	Rectangle player = { position.x,position.y,size,size };
	
	switch (t.GetType())
	{
	case TileType::Brick:
		if (t.GetIsActive())
		{
			if (CheckCollisionRecs(player, t.GetBoxCollider()))
			{
				position.y = t.GetPosition().y - 70;
				velocity.y = 0;
				isGrounded = true;
			}
		}
		break;
	case TileType::Wall:
		if (t.GetIsActive())
			{
				if (CheckCollisionRecs(player, t.GetBoxCollider()))
				{
					if (velocity.x > 0) 
					{
						position.x = t.GetBoxCollider().x - 70;
						velocity.x = 0;
						isGrounded = true;
					}
					else if (velocity.x < 0) 
					{
						position.x = t.GetBoxCollider().x + 20;
						velocity.x = 0;
						isGrounded = true;					
					}
					else if (velocity.y > 0) 
					{
						position.y = t.GetBoxCollider().y - 70;
						velocity.y = 0;
						isGrounded = true;
					}
					else if (velocity.y < 0) 
					{
						position.y = t.GetBoxCollider().y + 20;
						velocity.y = 0;
					}
				}


			}


		break;
	case TileType::Stair:
		if (t.GetIsActive())
		{
			if (CheckCollisionRecs(player, t.GetBoxCollider()))
			{
				isGrounded = false;
				isOnStairs = true;
			}
			else
			{

			}
		}
		break;
	}


}
