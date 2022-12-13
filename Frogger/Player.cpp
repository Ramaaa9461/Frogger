#include "Player.h"



Player::Player()
{
	texture = LoadTexture("res/Images/frog.png");
	speed = GetScreenHeight() / 15; //Remplazar por la cantidad de columnas

	goToInitialPosition();

	boxCollider.width = texture.width;
	boxCollider.height = texture.height;
	boxCollider.x = position.x;
	boxCollider.y = position.y;
}

void Player::goToInitialPosition()
{
	position.x = GetScreenWidth() / 2;
	position.y = GetScreenHeight() - texture.height;

	boxCollider.x = position.x;
	boxCollider.y = position.y;
}

Player::~Player()
{
	UnloadTexture(texture);
}


void Player::moveUp()
{
	if (position.y - speed > 0)
	{
		position.y -= speed;
		boxCollider.y = position.y;
	}
}

void Player::moveDown()
{
	if (position.y + speed < GetScreenHeight())
	{
		position.y += speed;
		boxCollider.y = position.y;
	}
}

void Player::moveRight()
{
	if (position.x + speed < GetScreenWidth())
	{
		position.x += speed;
		boxCollider.x = position.x;
	}
}

void Player::moveLeft()
{
	if (position.x - speed > 0)
	{
		position.x -= speed;
		boxCollider.x = position.x;
	}
}

void Player::addSpeed(int speed)
{
	position.x += speed;
	boxCollider.x = position.x;
}

void Player::substractLife()
{
	if (lifes > 0)
	{
		lifes--;
	}
}

void Player::draw()
{
	//DrawRectangleRec(boxCollider, RED);
	DrawTexture(texture, position.x, position.y, WHITE);
}

int Player::getLife()
{
	return lifes;
}

int Player::getFrogPlaced()
{
	return frogPlaced;
}

void Player::addFrogPlaced()
{
	frogPlaced++;
}

Rectangle Player::getBoxCollider()
{
	return boxCollider;
}
