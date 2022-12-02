#pragma once

#include "Entity.h"

class Cars : public Entity
{

private:

	int direction;

	void goToInitialPosition();

public: 
	
	Cars(const char* imagePath, int raw, int direction);
	~Cars();

	void move();

	void draw() override;
};

