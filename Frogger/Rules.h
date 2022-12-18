#pragma once

#include "raylib.h"

#include "SceneManager.h"
#include "AssetsImporter.h"

class Rules
{
private:
	AssetsImporter* AI;
	Texture background;
	Font font;

	Rectangle button1;

	void setButtons(Rectangle& rectangle, int sizeX, int sizeY, int difWidth, int difHeight);

public:

	void initRules();
	void updateRules();
	void drawRules();
};

