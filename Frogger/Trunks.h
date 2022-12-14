#pragma once

#include "Entity.h"

class Trunks : public Entity
{

private:

	Rectangle waterRigth;
	Rectangle waterLeft;
	void goToInitialPosition() override;

public:

	Trunks(Texture _texture, int raw, int direction, float speed, int positionX);
	~Trunks();

	void move() override;
	void checkCollision(Player* player) override;
	void draw() override;

};

