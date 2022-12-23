#include "Cars.h"



void Cars::goToInitialPosition()
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

Cars::Cars(Texture _texture, int raw, int direction, float speed) :
	Entity(_texture, raw, direction, speed)
{
	goToInitialPosition();
}

Cars::~Cars()
{
}

void Cars::move()
{
	if (direction == 0)
	{
		position.x += speed * GetFrameTime();
	}
	else
	{
		position.x -= speed * GetFrameTime();
	}

	if (position.x > GetScreenWidth() + boxCollider.width + 1 ||
		position.x < 0 - boxCollider.width - 5)
	{
		goToInitialPosition();
	}

	boxCollider.x = position.x;
}

void Cars::checkCollision(Player* player)
{
	if (CheckCollisionRecs(boxCollider, player->getBoxCollider()))
	{
		goToInitialPosition();
		player->goToInitialPosition();
		player->substractLife();
	}

}

void Cars::draw()
{
	//DrawRectangleRec(boxCollider, YELLOW);
	DrawTexture(texture, position.x, position.y, WHITE);
}

