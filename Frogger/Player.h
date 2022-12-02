#pragma once

#include "Entity.h"

class Player : public Entity
{
private:

	int lifes = 5;

public:

	Player();
	~Player();

	void moveUp();// Llamar a un sonido cada vez qe se mueve alguno
	void moveDown();
	void moveRight();
	void moveLeft();

	bool checkCollisionWithPlayer(Rectangle obstacle);
	void goToInitialPosition();
	void substractLife();


	int getLife();

	void draw() override;
	//Rectangle getBoxCollider()override;

};

