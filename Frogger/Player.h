#pragma once

#include "raylib.h"

class Player 
{
private:


	float speed = 1;
	Vector2 position;
	Rectangle boxCollider;
	Texture2D texture;
	int lifes = 5;

public:

	Player();
	~Player();

	void moveUp();// Llamar a un sonido cada vez qe se mueve alguno
	void moveDown();
	void moveRight();
	void moveLeft();

	void goToInitialPosition();
	void substractLife();


	int getLife();

	void draw();
	Rectangle getBoxCollider();

};

