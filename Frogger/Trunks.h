#pragma once

#include "Entity.h"

class Trunks : public Entity
{

private:

	void goToInitialPosition() override;

public:

	Trunks(const char* imagePath, int raw, int direction, float speed, int positionX);
	~Trunks();

	void move() override;
	void checkCollision(Player* player) override;
	void draw() override;

};

