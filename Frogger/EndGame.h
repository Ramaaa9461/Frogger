#pragma once

#include "raylib.h"
#include "AssetsImporter.h"

class EndGame
{
private:

	AssetsImporter* AI;
	Texture background;
	Font font;

	Rectangle button1;
	Rectangle button2;

	const char* text;

	bool playerHaveWon = false;

public:

	void initEndGame();
	void update();
	void draw();

	void resetValues();
	void setButtons(Rectangle& rectangle, int sizeX, int sizeY, int difWidth, int difHeight);
};

