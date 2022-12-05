#pragma once

#include "Entity.h"

class Cars : public Entity
{

private:

	void goToInitialPosition() override;

public: 
	
	Cars(const char* imagePath, int raw, int direction, float speed);
	~Cars();

	void move() override;
	void checkCollision(Player* player) override;
	void draw() override;
};

