#pragma once

#include "Entity.h"

class Trunks : public Entity
{

private:

	Rectangle waterLeft;
	Rectangle waterRight;

	void goToInitialPosition() override;

public:

	Trunks(const char* imagePath, int raw, int direction, float speed);
	~Trunks();

	void move() override;
	void checkCollision(Player* player) override;
	void draw() override;

};

