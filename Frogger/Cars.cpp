#include "Cars.h"



Cars::Cars(const char* imagePath, int raw, int direction)
{
	texture = LoadTexture(imagePath);
	position.y = GetScreenHeight() / raw;
	this->direction = direction;

	goToInitialPosition();

	boxCollider.width = texture.width;
	boxCollider.height = texture.height;
	boxCollider.x = position.x;
	boxCollider.y = position.y;
}

Cars::~Cars()
{
	UnloadTexture(texture);
}

void Cars::move()
{
	if (direction == 0)
	{
		position.x += speed;
	}
	else
	{
		position.x -= speed;
	}

	boxCollider.x = position.x;
}

void Cars::draw()
{
	DrawRectangleRec(boxCollider, YELLOW);
	DrawTexture(texture, position.x, position.y, WHITE);
}

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