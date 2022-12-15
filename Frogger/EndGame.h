#pragma once

#include "raylib.h"

class EndGame
{
private:

	bool playerHaveWon = false;
	Font font;

public:

	void initEndGame();
	void update();
	void draw();

};

