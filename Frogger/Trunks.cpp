#include "Trunks.h"



Trunks::Trunks(const char* imagePath, int raw, int direction, float speed) :
	Entity(imagePath, raw, direction, speed)
{
	goToInitialPosition();
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

	waterLeft.x = position.x - GetScreenWidth();
	waterLeft.y = position.y ;
	waterLeft.height = boxCollider.height;
	waterLeft.width = GetScreenWidth();

	waterRight.x = position.x + boxCollider.width;
	waterRight.y = position.y ;
	waterRight.height = boxCollider.height;
	waterRight.width = GetScreenWidth();
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

	waterLeft.x = position.x - GetScreenWidth();
	waterRight.x = position.x + boxCollider.width;
}

void Trunks::checkCollision(Player* player)
{
	if (CheckCollisionRecs(boxCollider, player->getBoxCollider()))
	{
		//Agregarle la velocidad al player para que se "Suba" al tronco
		player->addSpeed(speed);
	}
	else if (CheckCollisionRecs(waterLeft, player->getBoxCollider()) || 
			 CheckCollisionRecs(waterRight, player->getBoxCollider()))
	{
		goToInitialPosition();
		player->goToInitialPosition();
		player->substractLife();
	}


}

void Trunks::draw()
{
	DrawRectangleRec(waterLeft, SKYBLUE);
	DrawRectangleRec(waterRight, SKYBLUE);
	DrawTexture(texture, position.x, position.y, WHITE);
}
