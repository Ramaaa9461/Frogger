#include "Trunks.h"



Trunks::Trunks(const char* imagePath, int raw, int direction, float speed, int positionX) :
	Entity(imagePath, raw, direction, speed)
{
	//goToInitialPosition();
	position.x = positionX;
}

Trunks::~Trunks()
{
	UnloadTexture(texture);
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
		position.x < 0 - boxCollider.width - 5)
	{
		goToInitialPosition();
	}

	boxCollider.x = position.x;
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
}

void Trunks::draw()
{
	DrawRectangleRec(boxCollider, RED);
	DrawTexture(texture, position.x, position.y, WHITE);
}
