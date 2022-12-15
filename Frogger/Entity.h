#pragma once

#include "raylib.h"
#include "Player.h"

class Entity
{
protected:

	int direction;
	float speed = 1;
	Vector2 position;
	Rectangle boxCollider;
	Texture2D texture;

	virtual void goToInitialPosition() = 0;

public:

	Entity(Texture _texture, int raw, int direction, float speed);
	virtual ~Entity();
	
	
	virtual void move() = 0;
	virtual void draw() = 0;
	virtual void checkCollision(Player* player) = 0;
	
	
	Rectangle getBoxCollider();
};

