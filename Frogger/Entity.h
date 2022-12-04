#pragma once

#include "raylib.h"
#include "Player.h"

class Entity
{
protected:

	float speed = 1;
	Vector2 position;
	Rectangle boxCollider;
	Texture2D texture;

public:


	virtual ~Entity();
	virtual void draw() = 0;
	virtual void checkCollision(Player* player) = 0;
	Rectangle getBoxCollider();
};

