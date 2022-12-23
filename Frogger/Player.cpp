#include "Player.h"

#include "AssetsImporter.h"

Player::Player()
{
	texture = AssetsImporter::getAssetsImporter()->getFrog();
	speed = GetScreenHeight() / 15; //Remplazar por la cantidad de columnas
	jump = AssetsImporter::getAssetsImporter()->getJumpSound();
	lose = AssetsImporter::getAssetsImporter()->getLoseSound();
	SetSoundVolume(jump, 0.5f);

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

Player::~Player() { }

void Player::moveUp()
{
	if (position.y - speed > 0)
	{
		position.y -= speed;
		boxCollider.y = position.y;
		PlaySound(jump);
	}
}

void Player::moveDown()
{
	if (position.y + speed < GetScreenHeight())
	{
		position.y += speed;
		boxCollider.y = position.y;
		PlaySound(jump);
	}
}

void Player::moveRight()
{
	if (position.x + speed < GetScreenWidth())
	{
		position.x += speed;
		boxCollider.x = position.x;
		PlaySound(jump);
	}
}

void Player::moveLeft()
{
	if (position.x - speed > 0)
	{
		position.x -= speed;
		boxCollider.x = position.x;
		PlaySound(jump);
	}
}

void Player::addSpeed(int speed)
{
	position.x += speed * GetFrameTime();
	boxCollider.x = position.x;
}

void Player::substractLife()
{
	if (lifes > 0)
	{
		lifes--;
		PlaySound(lose);
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

void Player::setLife(int lifes)
{
	this->lifes = lifes;
}

void Player::setFrogPlaced(int frogPlaced)
{
	this->frogPlaced = frogPlaced;
}

Rectangle Player::getBoxCollider()
{
	return boxCollider;
}
