#include "Trunks.h"



Trunks::Trunks(Texture _texture, int raw, int direction, float speed, int positionX) :
	Entity(_texture, raw, direction, speed)
{
	//goToInitialPosition();
	position.x = positionX;
	boxCollider.x = positionX;

	waterRigth.x = position.x +boxCollider.width;
	waterRigth.y = position.y;
	waterRigth.height = boxCollider.height;
	waterRigth.width = GetScreenWidth()/3 - boxCollider.width;

	waterLeft.x = position.x - (GetScreenWidth() / 3 - boxCollider.width);
	waterLeft.y = position.y;
	waterLeft.height = boxCollider.height;
	waterLeft.width = GetScreenWidth() / 3 - boxCollider.width;
}

Trunks::~Trunks()
{
}


void Trunks::goToInitialPosition()
{
	if (direction == 0)
	{
		position.x = 0 - texture.width;
	}
	else
	{
		position.x = GetScreenWidth() + texture.width;
	}
}

void Trunks::move()
{
	if (direction == 0)
	{
		position.x += speed;
	}
	else
	{
		position.x -= speed;
	}

	if (position.x > GetScreenWidth() + boxCollider.width + 1 ||
		position.x < 0 - boxCollider.width - 1)
	{
		goToInitialPosition();
	}

	boxCollider.x = position.x;
	waterRigth.x = position.x + boxCollider.width;
	waterLeft.x = position.x - (GetScreenWidth() / 3 - boxCollider.width);
}

void Trunks::checkCollision(Player* player)
{
	if (CheckCollisionRecs(boxCollider, player->getBoxCollider()))
	{
		if (direction == 0)
		{
			player->addSpeed(speed);
		}
		else
		{
			player->addSpeed(-speed);
		}
	}
	else if(CheckCollisionRecs(waterLeft, player->getBoxCollider()) || CheckCollisionRecs(waterRigth, player->getBoxCollider()))
	{
		player->substractLife();
		player->goToInitialPosition();
	}
}

void Trunks::draw()
{
	//DrawRectangleRec(waterRigth, SKYBLUE);
	//DrawRectangleRec(waterLeft, SKYBLUE);
	//DrawRectangleRec(boxCollider, RED);
	DrawTexture(texture, position.x, position.y, WHITE);
}
